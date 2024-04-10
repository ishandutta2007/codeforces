#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 30100
using namespace std;
using pii = pair<int,int>;
int n, K, Q, w[N_], Tw[N_];
long long D[5][N_], P[N_], U[5][N_], S[5][N_];
void Solve(){
    int i, j, k;
    scanf("%d%d%d",&n,&K,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=0;i<=4;i++){
        for(j=0;j<=n;j++){
            U[i][j]=D[i][j]=S[i][j]=0;
        }
    }
    for(i=0;i<=K;i++)U[i][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=K;j++)U[j][i]=U[j][i-1];
        for(j=1;j<=K && j<i;j++){
            for(k=j;k<=K;k++){
                U[k][i] += U[k-j][i-j-1];
                U[k][i] = U[k][i];
            }
        }
    }
    for(i=1;i<=K;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=i && j+k<=n;k++){
                if(w[j+k] < w[j]){
                    D[i][j] += U[i-k][n-(j+k)];
                    D[i][j] = D[i][j];
                }
            }
        }
    }
    for(i=1;i<=K;i++){
        for(j=1;j<=n;j++){
            S[i][j]=S[i][j-1]+D[i][j];
            //if(j%100==0)printf("%lld\n",U[i][j]);
        }
        //puts("");
    }
    while(Q--){
        int loc;
        long long M;
        scanf("%d%lld",&loc,&M);
        if(M > U[K][n]){
            puts("-1");
            continue;
        }
        int ed = 0, TK = K;
        while(1){

            int bb = ed+1, ee = n, rr = ed;
            while(bb<=ee){
                int m = (bb+ee)>>1;
                long long sm = S[TK][m] - S[TK][ed];
                long long dd = U[TK][n-m];
                if(sm < M && sm + dd >= M){
                    rr = m;
                    bb = m+1;
                }
                else{
                    ee = m-1;
                }
            }

            if(loc <= rr){
                printf("%d\n",w[loc]);
                break;
            }

            M -= (S[TK][rr] - S[TK][ed]);
            int pv = rr+1;

            vector<pii>ZZ;
            for(i=0;i<=TK && pv+i <=n;i++){
                ZZ.push_back({w[pv+i],i});
            }
            sort(ZZ.begin(),ZZ.end());
            int fin = 0;
            for(auto &t : ZZ){
                int l = t.second;
                if(M <= U[TK-l][n-(pv+l)]){
                    for(i=pv;i<=pv+l;i++)Tw[i]=w[i];
                    reverse(Tw+pv,Tw+pv+l+1);
                    if(loc <= pv+l){
                        printf("%d\n",Tw[loc]);
                        fin=1;
                        break;
                    }
                    ed = pv+l;
                    TK-=l;
                    break;
                }
                else M-=U[TK-l][n-(pv+l)];
            }
            if(fin)break;
        }
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}
#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define N_ 301000
using namespace std;
int n, Q, L[N_], w[N_], BIT[N_], R[N_];
vector<int>G[N_];
vector<pii>Z[N_];
void Add(int a){
    while(a<=n){
        BIT[a]++;
        a+=(a&-a);
    }
}
int Sum(int a){
    int r=0;
    while(a){
        r+=BIT[a];
        a-=(a&-a);
    }
    return r;
}
void Solve(){
    int i;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        int d = i-w[i];
        if(d>=0){
            if(d==0){
                L[i]=i;
            }
            else{
                int tot = Sum(i);
                if(tot >= d){
                    int b = 1, e = i, mid, r=0;
                    while(b<=e){
                        mid = (b+e)>>1;
                        if(tot - Sum(mid-1) >= d){
                            r=mid;
                            b=mid+1;
                        }
                        else e=mid-1;
                    }
                    L[i]=r;
                }
            }
        }
        if(L[i]){
            Add(L[i]);
            G[L[i]].push_back(i);
        }
        //printf("%d %d\n",i,L[i]);
    }
    for(i=0;i<N_;i++)BIT[i]=0;
    for(i=1;i<=Q;i++){
        int b, e, x, y;
        scanf("%d%d",&x,&y);
        b=x+1,e=n-y;
        Z[b].push_back({e,i});
    }
    for(i=n;i>=1;i--){
        for(auto &t : G[i]) Add(t);
        for(auto &t : Z[i]){
            R[t.second] = Sum(t.first) - Sum(i-1);
        }
    }
    for(i=1;i<=Q;i++)printf("%d\n",R[i]);
}
int main(){
    int TC=1;
    while(TC--){
        Solve();
    }
}
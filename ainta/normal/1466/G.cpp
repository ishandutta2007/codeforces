#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using pii = pair<int,int>;
int n, Q, L[101000], oto[1010000], C[26];
long long po[1010000], Mod = 1000000007, SS[26][101000];
char q[110], T[101000];
char p[2010000], U[1010000];

int AA[1010000], BB[1010000];
void Solve(){
    int i, j;
    scanf("%d%d",&n,&Q);
    scanf("%s",q);
    scanf("%s",T);
    for(i=0;q[i];i++)p[i]=q[i];
    L[0] = i;
    for(i=0;T[i] && L[i] <= 1000000;i++){
        L[i+1]=L[i];
        p[L[i+1]++] = T[i];
        for(j=0;j<L[i];j++){
            p[L[i+1]++] = p[j];
        }
    }

    for(i=0;i<26;i++){
        for(j=0;j<n;j++){
            SS[i][j+1]=SS[i][j]*2;
            if(T[j]=='a'+i)SS[i][j+1]++;
            SS[i][j+1]%=Mod;
        }
    }
    while(Q--){
        int K, l;
        scanf("%d",&K);
        scanf("%s",U);
        for(i=0;U[i];i++);
        l=i;
        int pv = -1;
        for(i=1;i<=l;i++)AA[i]=BB[i]=0;
        for(i=1;i<=K;i++){
            if(L[i]>l){
                pv=i;
                break;
            }
        }
        oto[0]=-1;
        for(i=0;i<l;i++){
            int t = oto[i];
            while(t!=-1 && U[t]!=U[i])t=oto[t];
            oto[i+1] = t+1;
        }
        if(pv==-1){
            int t = 0, ans = 0;
            for(i=0;i<L[K];i++){
                while(t!=-1 && p[i]!=U[t])t=oto[t];
                t++;
                if(t==l){
                    ans++;
                }
            }
            printf("%d\n",ans);
            continue;
        }
        int t = 0;
        long long c=0;
        for(i=0;i<L[pv];i++){
            while(t!=-1 && p[i]!=U[t])t=oto[t];
            t++;
            if(t==l)c++;
        }
        while(t>0){
            AA[t]=1;
            t=oto[t];
        }
        reverse(U,U+l);
        oto[0]=-1;
        for(i=0;i<l;i++){
            int t = oto[i];
            while(t!=-1 && U[t]!=U[i])t=oto[t];
            oto[i+1] = t+1;
        }


        for(i=L[pv]-1;i>=0;i--){
            while(t!=-1 && p[i]!=U[t])t=oto[t];
            t++;
        }

        while(t>0){
            BB[t]=1;
            t=oto[t];
        }

        long long ans = c*po[K-pv]%Mod;
        reverse(U,U+l);

        for(i=0;i<26;i++)C[i]=0;
        AA[0]=BB[0]=1;
        for(i=0;i<=l-1;i++){
            if(AA[i] && BB[l-i-1]){
                C[U[i]-'a']++;
                //printf("! %c\n",U[i]);
            }
        }
        for(i=0;i<26;i++){
            ans = (ans + C[i] * (SS[i][K]-SS[i][pv]*po[K-pv]%Mod+Mod))%Mod;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int TC = 1, i;
    po[0]=1;
    for(i=1;i<=1000000;i++)po[i]=po[i-1]*2%Mod;
    while(TC--){
        Solve();
    }
}
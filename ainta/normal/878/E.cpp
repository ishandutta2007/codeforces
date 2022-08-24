#include<cstdio>
#include<algorithm>
using namespace std;
int n, Q, w[101000], Nxt[101000][20], Mod = 1000000007, Sum[101000][20], SS[101000], po[101000], Ipo[101000];
int Get(int b, int e){
    return 1ll*(SS[e]-SS[b-1]+Mod)*Ipo[b-1]%Mod;
}
int Calc(int b, int e){
    int i;
    long long r = 0;
    for(i=17;i>=0;i--){
        if(Nxt[e][i] >= b){
            r = (r+Sum[e][i])%Mod;
            e = Nxt[e][i];
        }
    }
    r = (r + Get(b,e))%Mod;
    return r;
}
int main(){
    int i, j;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    po[0]=Ipo[0]=1;
    for(i=1;i<=n;i++){
        po[i]=po[i-1]*2%Mod;
        Ipo[i]=Ipo[i-1]*500000004ll%Mod;
    }
    for(i=1;i<=n;i++){
        SS[i] = (SS[i-1] + 1ll*po[i]*(Mod+w[i]))%Mod;
    }
    for(i=1;i<=n;i++){
        long long s = 0;
        if(w[i]<=0){
            Nxt[i][0] = i-1;
            Sum[i][0] = (Mod+w[i])*2%Mod;
        }
        for(j=i;j>=1;j--){
            s=(s+w[j])*2;
            if(s<=0){
                Nxt[i][0] = j-1;
                Sum[i][0] = (s+Mod*10ll)%Mod;
                break;
            }
            if(s>2e9){
                Nxt[i][0] = -1;
                break;
            }
        }
    }
    for(i=0;i<18;i++){
        for(j=1;j<=n;j++){
            if(Nxt[j][i] == -1)Nxt[j][i+1] = -1;
            else{
                Nxt[j][i+1] = Nxt[Nxt[j][i]][i];
                Sum[j][i+1] = (Sum[Nxt[j][i]][i] + Sum[j][i])%Mod;
            }
        }
    }
    while(Q--){
        int b, e;
        scanf("%d%d",&b,&e);
        printf("%d\n",(0ll + w[b] + Mod + Calc(b+1,e))%Mod);
    }
}
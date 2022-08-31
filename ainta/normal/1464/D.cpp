#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[1010000], vis[1010000], Mod = 1000000007, C[5];
long long D[1010000];
void Solve(){
    int i;
    for(i=0;i<5;i++)C[i]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        vis[i]=0;
        scanf("%d",&w[i]);
    }
    int res = 0;
    printf("%lld ",D[n]);
    for(i=1;i<=n;i++){
        if(vis[i])continue;
        int x = i;
        int c = 0;
        while(1){
            c++;
            vis[x]=1;
            x=w[x];
            if(x==i)break;
        }
        if(c>=5){
            int z = (c-2)/3;
            res += z;
            c-=z*3;
        }
        C[c]++;
    }
    if(C[4]>1){
        res += C[4]-1;
        C[1] += C[4]-1;
        C[4] = 1;
    }

 
    if(n%3 == 0 || n%3 == 2){
        if(C[4]){
            res += C[4];
            C[1] += C[4];
            C[4]=0;
        }
        int t = min(C[1],C[2]);
        C[1]-=t;
        C[2]-=t;
        res += t;
        if(C[1]){
            t = C[1]/3;
            res += t*2;
            C[1]%=3;
            if(C[1]==2){
                res++;
            }
        }
        else{
            res += (C[2]/3)*3;
        }
        printf("%d\n",res);
        return;
    }
 
    if(C[4]){
        if(C[1] < C[2]){
            C[2]--,C[4]--;
            res+=2;
        }
        else{
            int t = min(C[1],C[2]);
            C[1]-=t,C[2]-=t;
            res += t;
            res += C[1]/3*2 + C[2]/3*3;
            printf("%d\n",res);

            return;
        }
    }
 
    if(C[2]==0){
        if(C[1]==1){
            res++;
        }
        else{
            res += C[1]/3*2;
        }
        printf("%d\n",res);
        return;
    }
    if(C[2]==1){
        C[1]-=2;
        C[2]++;
        res++;
    }
 
    int t = min(C[1],C[2]-2);
    if(t<0){
        t=0;
    }
    res += t;
    C[1]-=t,C[2]-=t;
    if(C[1]==0){
        res += (C[2]-2)/3*3;
    }
    else{
        res += C[1]/3*2;
    }
    printf("%d\n",res);
 
    
}
int main(){
    int TC;
    scanf("%d",&TC);
    int i;
    D[1]=1;
    D[2]=2;
    D[3]=3;
    D[4]=4;
    for(i=5;i<=1000000;i++)D[i]=D[i-3]*3%Mod;
    while(TC--){
        Solve();
    }
}
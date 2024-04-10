#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long w[101000], S[101000];
int n;
int main(){
    int i, b, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(i!=1){
            w[i-1] = abs(b-a);
        }
        b = a;
    }
    for(i=1;i<=n;i++){
        S[i]=S[i-1];
        if(i%2)S[i]+=w[i];
        else S[i]-=w[i];
    }
    long long Mn = 1e18, Mx = -1e18, Res = -1e18;
    for(i=n-1;i>=1;i--){
        Mn = min(Mn, S[i]);
        Mx = max(Mx, S[i]);
        if(i%2){
            Res = max(Res, Mx - S[i-1]);
        }
        else{
            Res = max(Res, S[i-1] - Mn);
        }
    }
    printf("%lld\n",Res);
}
#include<cstdio>
#include<algorithm>
using namespace std;
int TC;
int n, w[201000], T[201000];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    long long s=0;
    for(i=1;i<n;i++){
        T[i] = abs(w[i]-w[i+1]);
        s+=T[i];
    }
    long long res = s;
    res=min(res,s-T[1]);
    res=min(res,s-T[n-1]);
    for(i=2;i<n;i++){
        res=min(res,s-T[i-1]-T[i]+abs(w[i+1]-w[i-1]));
    }
    printf("%lld\n",res);
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll=long long;
const int N=200005,P=1000000007;
ll cal(ll x){
    ll p=sqrt(x)+1e-10;
    if(p*p+2*p<=x) return p*3;
    else if(p*p+p<=x) return p*3-1;
    else return p*3-2;
}
void work(){
    ll l,r;
    cin>>l>>r;
    cout<<cal(r)-cal(l-1)<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    // for(int i=1;i<=20;i++)
    //     printf("%d %lld\n",i,cal(i));
    cin>>t;
    while(t--) work();
    return 0;
}
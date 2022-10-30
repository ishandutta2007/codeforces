// ++ //
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 2e5+228;
ll a[N];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, x=0;
    cin >> n;
    for(ll i = 1;i<=n;i++){
        cin >> a[i];
        x^=a[i];
    }
    if(n&1){
        cout<<"YES\n";
        cout<<(n-1)/2+(n-3)/2<<'\n';
        cout<<"1 2 3\n";
        for(ll i = 5;i<=n;i+=2){
            cout<<i <<' '<<i-1<<' '<<i-2<<'\n';
        }
        for(ll i = n-4;i>0;i-=2){
            cout<<i <<' '<<i+1<<' '<<i+2<<'\n';
        }
    }else{
        if(x) return cout<<"NO\n", 0;
        cout<<"YES\n";
        cout<<(n-2)/2+(n-4)/2<<'\n';
        cout<<"1 2 3\n";
        for(ll i = 5;i<=n;i+=2){
            cout<<i <<' '<<i-1<<' '<<i-2<<'\n';
        }
        for(ll i = n-5;i>0;i-=2){
            cout<<i <<' '<<i+1<<' '<<i+2<<'\n';
        }
    }
}
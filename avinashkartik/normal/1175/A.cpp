#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e5+3;

ll a[N],vis[N],ans;
ll n,sum,t,k;
string s;
stack <ll> st;
ll m;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        ans = 0;
        while(n != 0){
            if(n%k == 0) ans++;
            else ans += n%k+1;
            n /= k;
        }
        cout<<ans-1<<endl;
    }
}
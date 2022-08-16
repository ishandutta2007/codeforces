#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e5+3;

ll a[N],vis[N],ans[N];
ll n,sum,k;

int main(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    ans[n] = a[n];
    for(int i = n-1; i > 0; i--){
        ans[i] = ans[i+1] + a[i];
    }
    sum = ans[1];
    ans[1] = -INF;
    sort(ans+1,ans+n+1);
    for(int i = n; i > n-k+1; i--) sum += ans[i];
    cout<<sum<<endl;
}
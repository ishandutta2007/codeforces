#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll vis[N];
void Main(){
    ll n,a,b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) vis[i]=0;

    if (a>(n-1)/2 || b>(n-1)/2 || (a+b)>n-2 || abs(a-b)>1){
        cout << -1 << endl;
        return ;
    }
    if (a>b){
        for (int i=1;i<=2*a;i++){
            if (i%2==1) vis[i/2+1]=1,cout << (i/2)+1 << " ";
            else vis[n-(i/2)+1]=1,cout << n-(i/2)+1 << " ";
        }
        for (int i=n;i;i--){
            if (vis[i]==0) cout << i << " ";
        }
        cout << endl;
    }
    if (a<b){
        for (int i=1;i<=2*b;i++){
            if (i%2==0) vis[i/2]=1,cout << (i/2) << " ";
            else vis[n-(i/2)]=1,cout << n-(i/2) << " ";
        }
        for (int i=1;i<=n;i++){
            if (vis[i]==0) cout << i << " ";
        }
    }
    if (a==b){
       // cout << " 3o4ji " << endl;
        for (int i=1;i<=2*a+1;i++){
            if (i%2==1) vis[i/2+1]=1,cout << (i/2)+1 << " ";
            else vis[n-(i/2)+1]=1,cout << n-(i/2)+1 << " ";
        }
        for (int i=1;i<=n;i++){
            if (vis[i]==0) cout << i << " ";
        }
    }
    cout << endl;
    return ;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
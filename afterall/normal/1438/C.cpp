#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e2+100,M=31;
ll a[N][N];
map <int,int> mp;
int Main(){
    vector <int> v;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> a[i][j];
            v.pb(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i=0;i<v.size();i++){
        mp[v[i]]=i+1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[a[i][j]]%2==1){
                if ((i+j)%2==1) a[i][j]++;
            }
            else{
                if ((i+j)%2==0) a[i][j]++;
            }
            cout << a[i][j] << " ";
        }
        cout << endl;

    }
    //cout << endl;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}
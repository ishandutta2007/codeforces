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
const int N=3e2+100;
ll t[3];
char a[N][N];
int Main(){
    memset(t,0,sizeof t);
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]=='X'){
                t[(i+j)%3]++;
            }
        }
    }
    ll z=0;
    if (t[1]<=t[2] && t[1]<=t[0]) z=1;
    if (t[2]<=t[1] && t[2]<=t[0]) z=2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]=='X' && (i+j)%3==z){
                a[i][j]='O';
            }
            cout << a[i][j] ;
        }
        cout << endl;
    }
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
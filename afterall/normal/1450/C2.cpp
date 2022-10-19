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
ll d[3];
char a[N][N];
int Main(){
    memset(t,0,sizeof t);
    memset(d,0,sizeof d);
    ll n;
    cin >> n;
    ll s=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]=='X'){
                t[(i+j)%3]++;
                s++;
            }
            else if (a[i][j]=='O'){
                d[(i+j)%3]++;
                s++;
            }
        }
    }
    ll p1=0,p2=1;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i==j) continue;
            if (t[i]+d[j]<=s/3){
                p1=i,p2=j;
            }
        }
    }
   // cout << p1 << " " << p2 << endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]=='X' && (i+j)%3==p1){
                a[i][j]='O';
            }
            else if (a[i][j]=='O' && (i+j)%3==p2){
                a[i][j]='X';
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
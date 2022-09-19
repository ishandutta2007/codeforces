#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e2 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll a[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    ll x, y;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==0){
                x = i;
                y = j;
            }
        }
    }
    ll ss;
    ll s = 0;
    for(int i =0;i<n;i++){
        s += a[(x+1)%n][i];
    }
    ss = s;
    for(int i = 0;i<n;i++){
        s -= a[x][i];
    }
    if(s<=0){
        cout << -1;
        return 0;
    }
    a[x][y] = s;
    //debug(s);
    for(int i =0;i<n;i++){
        s = 0;
        for(int j =0;j<n;j++){
            s+=a[i][j];
        }
        if(s!=ss){
            cout << -1;
            return 0;
        }
        s = 0;
        for(int j =0;j<n;j++){
            s+=a[j][i];
        }
        if(s!=ss){
            cout << -1;
            return 0;
        }
    }
    s = 0;
    for(int i =0;i<n;i++){
        s+=a[i][i];
    }
    if(s!=ss){
        cout << -1;
        return 0;
    }
    s = 0;
    for(int i =0;i<n;i++){
        s+=a[i][n-1-i];
    }
    if(s!=ss){
        cout << -1;
        return 0;
    }
    cout << a[x][y];
    return 0;
}

/*
*/
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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

str a[1000];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    str s;
    ll f = 0;
    for(int i =0;i<n;i++){
        cin >> s;
        if(s[0] == 'O' and s[1] == 'O' and f == 0){
            f = 1;
            s[0] = '+';
            s[1] = '+';
        }
        if(s[3] == 'O' and s[4] == 'O' and f == 0){
            f = 1;
            s[3] = '+';
            s[4] = '+';
        }

        a[i] = s;
    }
    if(f==0)cout << "NO";
    else{
        cout << "YES" << endl;
        for(int i =0;i<n;i++) cout << a[i] << endl;
    }
    return 0;
}

/*
*/
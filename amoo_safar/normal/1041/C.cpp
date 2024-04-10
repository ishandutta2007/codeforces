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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;

ll out[MAXN];
ll a[MAXN];
ll b[MAXN];

bool CMP(ll i, ll j){
    return a[i] < a[j];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, d;
    cin >> n >> m >> d;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n;i++)b[i] = i;
    sort(b, b + n, CMP);
    ll p1 = 0;
    ll p2 = 1;
    ll l = 1;
    out[b[0]] = 1;
    while(p2 < n){
        if(a[b[p2]] - a[b[p1]] > d){
            out[b[p2]] = out[b[p1]];
            p1++;
        } else {
            l++;
            out[b[p2]] = l;
        }
        p2 ++;
    }
    cout << l << endl;
    for(int i =0;i<n;i++)cout << out[i] << " ";
    return 0;

}
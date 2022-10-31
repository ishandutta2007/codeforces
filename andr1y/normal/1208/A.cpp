#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
    FAST;
    ll T;
    cin >> T;
    while(T--){
        ll a, b, n;
        cin >> a >> b >> n;
        ll axb = a^b;
        if(n%3 == 0) cout << a << endl;
        else if(n%3 == 1) cout << b << endl;
        else cout << axb << endl;
    }
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define m_p make_pair
#define p_b push_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
const ll N = 2e5;
const ll MAXN = 1123456;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll x, y, z;
    cin >> x >> y >> z;
    ll a, b, c;
    cin >> a >> b >> c;
    a -= x;
    if(a < 0)vout("NO");
    ll k = min(a, y);
    a -= k;
    y -= k;
    if(b < y)vout("NO");
    b -= y;
    if(b + c + a < z)vout("NO");
    vout("YES");

    return 0;
}
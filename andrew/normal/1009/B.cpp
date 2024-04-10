#include <bits/stdc++.h>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pll pair <ll,ll>
#define vl vector <ll>

typedef int ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=29000000;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;

ll binpow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n&1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
int main() {
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    string s;
    cin >> s;
    string s1;
    ll kol = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '1'){
            kol++;
        }
        if (s[i] != '1') s1 += s[i];
    }
    reverse(s1.begin(), s1.end());
    for (int i = 0; i < kol; ++i){
        s1 = s1 + '1';
    }
    reverse(s1.begin(), s1.end());
    ll pos = s.size();
    for (int i = 0; i < s1.size(); ++i){
        if (s1[i] == '2'){
            pos = i;
            break;
        }
    }
    sort(s1.begin(), s1.begin() + pos);
    cout << s1 << endl;
    return 0;
}
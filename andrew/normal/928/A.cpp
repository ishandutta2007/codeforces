#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

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

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n&1) ans*=a;
        a*=a;
        n >>= 1;
    }
    return ans;
}
string s;
ll n;
bool check(string s1){
    if (s1.size()!=s.size()) return 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] != s1[i]){
            char c1 =  s[i], c2 = s1[i];
            string kek = "1lIiL";
            if (toupper(s[i]) == s1[i] or toupper(s1[i])==s[i]) continue;
            c1 = s[i];
            c2 = s1[i];
            if ((c1 == '0' && c2 == 'O') or (c1 == 'O' && c2 == '0') or (c1 == '0' && c2 == 'o') or (c1 == 'o' && c2 == '0')) continue;
            if (kek.find(s[i]) != string :: npos && kek.find(s1[i]) != string :: npos) continue;
            return 0;
        }
    }
    return 1;
}
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        string s1;
        cin >> s1;
        if (check(s1) == 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
   return 0;
}
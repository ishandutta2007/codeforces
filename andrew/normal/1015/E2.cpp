#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

template <typename T>
T sqr(T x)
{
    return x * x;
}

template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}

ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}

const ll MAXN = 1123456;

int n, m;
ll pref[1001][1001], prefu[1001][1001];
char a[1001][1001];

ll z[1003][1003], zu[1003][1003];
ll b[1003][1003];

vector<pair<pll,ll> > ans;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + (a[i][j] == '*');
            prefu[i][j] = prefu[i - 1][j] + (a[i][j] == '*');
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '*'){
                ll l = 0, r = min(m - j, min(i - 1, min(n - i, j - 1)));
                ll p = r;


//                if (i == 3 && j == 5) cout << pref[i][j + r] << " " <<  pref[i][j - r - 1] << "+" << endl;
//                if (i == 3 && j == 5) cout << prefu[i + r][j] << " " <<  prefu[i - r - 1][j] << "+" << endl;

                while (l + 1 < r){
                    ll c = (l + r) / 2;
                    if ((prefu[i + c][j] - prefu[i - c - 1][j] == (i + c) - (i - c) + 1)
                     && (pref[i][j + c] - pref[i][j - c -1] == (i + c) - (i - c) + 1 )) l = c; else r = c - 1;
                }
                ll c = l + 1;
                while (l != p && (prefu[i + c][j] - prefu[i - c - 1][j] == (i + c) - (i - c) + 1)
                     && (pref[i][j + c] - pref[i][j - c -1] == (i + c) - (i - c) + 1 )) {
                    l = c;
                    c = l + 1;
                     }
//                if (i == 3 && j == 5) {
//                    cout << l << "___" << endl;
//                }

                if (l != 0) {
                    ans.p_b({{i, j}, l});
                    zu[i - l][j] += 1;
                    zu[i + l + 1][j] += -1;
                    z[i][j - l] += 1;
                    z[i][j + l + 1] += -1;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        ll o = 0;
        for (int j = 1; j <= m; j++) {
            o += z[i][j];
            b[i][j] += o;
        }
    }


    for (int j = 1; j <= m; j++) {
        ll o = 0;
        for (int i = 1; i <= n; i++) {
            o += zu[i][j];
            b[i][j] += o;
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) cout << b[i][j] << " ";
//        cout << endl;
//    }



    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*' && b[i][j] != 0) continue;
        if (a[i][j] != '*' && b[i][j] == 0) continue;
        cout << -1;
        return 0;
    }


    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se << endl;
    }

    return 0;
}
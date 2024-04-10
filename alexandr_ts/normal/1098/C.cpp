#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 1e15 + 10;
const ld EPS = 1e-6;


void solve(ll n, ll s) {
    if (2 * n - 1 > s || s > n * (n + 1) / 2) {
        cout << "No\n";
        return;
    }
    ll kl = 0, kr = n - 1;
    while (kr - kl > 1) {
        ll km = (kl + kr) / 2;
        ll curs = 0;
        if (km == 1) {
            curs = n * (n + 1) / 2;
        } else {
            vector<ll> pws = {1};
            ll lft = n - 1;
            while (lft) {
                pws.pb(pws.back() * km);
                if (pws.back() > lft) {
                    pws.back() = lft;
                    lft = 0;
                    break;
                } else {
                    lft -= pws.back();
                }
            }

            fr(i, pws.size())
                curs += pws[i] * (i + 1);
        }

        if (curs <= s)
            kr = km;
        else
            kl = km;
    }

    ll k = kr;

    vector<ll> cnt = {1};
    ll lft = n - 1;
    ll ss = s - 1;
    while (lft) {
//        for (auto x: cnt) cout << x << " ";cout << endl;
//        cout << lft << endl;

        for (ll i = 1; i <= lft && i <= cnt.back() * k; i++) {
            ll sprime = ss - i * (cnt.size() + 1);
            if (!sprime && lft == i) {
                cnt.pb(i);
                lft -= i;
                ss -= i * cnt.size();
                break;
            }

            ll sl = 0;
            ll tmp_lft = lft - i;
            ll curP = k;
            if (k == 1) {
                sl = (1 + cnt.size() + 1);
            } else {
                for (ll j = 1; ;j++) {
                    if (curP * i < tmp_lft) {
                        sl += i * curP * (1 + cnt.size() + j);
                        tmp_lft -= curP * i;
                    }
                    else {
                        sl += tmp_lft * (1 + cnt.size() + j);
                        tmp_lft = 0;
                        break;
                    }
                    curP *= k;
                }
            }
            ll sr = (cnt.size() + 1) * (lft - i) + (lft - i) * (lft - i + 1) / 2;
//            if (i == 5) {
//                cout << sl << " " << sprime << " " << sr << endl;
//                exit(0);
//            }
            if (sl <= sprime && sprime <= sr) {
                cnt.pb(i);
                lft -= i;
                ss -= i * cnt.size();
                break;
            }
        }
    }

//    fr(i, cnt.size())
//        cout << cnt[i] << " ";
//    cout << endl;

    vector<int> dep;
    fr(i, cnt.size())
        fr(j, cnt[i])
            dep.pb(i);
    vector<vector<int> > numsByDep(cnt.size(), vector<int>());
    fr(i, n)
        numsByDep[dep[i]].pb(i);

    vector<int> par(n, -1);
    frab(i, 1, cnt.size()) {
        fr(j, numsByDep[i].size()) {
            par[numsByDep[i][j]] = numsByDep[i - 1][j % numsByDep[i - 1].size()];
        }
    }
    cout << "Yes\n";
    frab(i, 1, n)
        cout << par[i] + 1 << " ";cout << endl;
    cout << endl;

}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, s;
    cin >> n >> s;
    //while (cin >> n >> s)
        solve(n, s);
}
#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 77;
const ld EPS = 1e-8;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int d[N][N][N][2];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    fr(i, n)
        if (s[i] != 'V' && s[i] != 'K')
            s[i] = 'A';
    vector <int> ks, vs, as;
    fr(i, n)
        if (s[i] == 'V') vs.pb(i);
        else if (s[i] == 'K') ks.pb(i);
        else as.pb(i);
    fr(i1, ks.size() + 1)
        fr(i2, vs.size() + 1)
            fr(i3, as.size() + 1)
                fr(i, 2)
                    d[i1][i2][i3][i] = INF;
    d[0][0][0][0] = 0;


//    for (auto t: ks) cout << t << " ";cout << endl;
//    for (auto t: vs) cout << t << " ";cout << endl;
//    for (auto t: as) cout << t << " ";cout << endl;


    fr(i1, ks.size() + 1)
        fr(i2, vs.size() + 1)
            fr(i3, as.size() + 1) {
                if (i1 < ks.size()) {
                    int cnt = 0;
                    frab(i, i2, vs.size())
                        if (vs[i] < ks[i1])
                            cnt++;
                    frab(i, i3, as.size())
                        if (as[i] < ks[i1])
                            cnt++;
                    d[i1 + 1][i2][i3][0] = min(d[i1 + 1][i2][i3][0], d[i1][i2][i3][0] + cnt);
                }
                if (i2 < vs.size()) {
                    int cnt = 0;
                    frab(i, i1, ks.size())
                        if (ks[i] < vs[i2])
                            cnt++;
                    frab(i, i3, as.size())
                        if (as[i] < vs[i2])
                            cnt++;
                    d[i1][i2 + 1][i3][1] = min(d[i1][i2 + 1][i3][1], d[i1][i2][i3][0] + cnt);
                    d[i1][i2 + 1][i3][1] = min(d[i1][i2 + 1][i3][1], d[i1][i2][i3][1] + cnt);
                }
                if (i3 < as.size()) {
                    int cnt = 0;
                    frab(i, i1, ks.size())
                        if (ks[i] < as[i3])
                            cnt++;
                    frab(i, i2, vs.size())
                        if (vs[i] < as[i3])
                            cnt++;
                    d[i1][i2][i3 + 1][0] = min(d[i1][i2][i3 + 1][0], d[i1][i2][i3][0] + cnt);
                    d[i1][i2][i3 + 1][0] = min(d[i1][i2][i3 + 1][0], d[i1][i2][i3][1] + cnt);
                }
            }
    cout << min(d[ks.size()][vs.size()][as.size()][0], d[ks.size()][vs.size()][as.size()][1]);
}
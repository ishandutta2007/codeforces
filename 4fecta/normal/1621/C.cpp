#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 10005;

int n, p[MN], q[MN], tim = 0;

int ask(int x) {
    tim++;
    cout << "? " << x << endl;
    int ret;
    cin >> ret;
    if (!ret) abort();
    return ret;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        tim = 0;
        for (int i = 1; i <= n; i++) p[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i]) continue;
            int f = ask(i), id = f;
            int curtim = tim;
            vector<pii> v;
            while (1) {
                int c = ask(i);
                v.push_back({c, id});
                id = c;
                if (c == f) break;
            }
            //for (pii pp : v) cout << pp.f << " " << pp.s << endl;
            //shift backwards by curtim
            //cout << curtim << endl;
            int st = curtim;
            st = 0;
            st %= v.size(), st += v.size(), st %= v.size();
            for (int j = 0; j < v.size(); j++) {
                int ii = st;
                st = (st + 1) % v.size();
                //cout << "ii: " << ii << " " << v[ii].s << endl;
                p[v[ii].s] = v[j].f;
            }
        }
        cout << "!";
        for (int i = 1; i <= n; i++) cout << " " << p[i];
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e3 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

struct team {
    string s, t, ans;
    int num;
} a[N];

bool cmp(team a, team b) {
    if (a.s[0] != b.s[0]) return a.s[0] < b.s[0];
    if (a.s[1] != b.s[1]) return a.s[1] < b.s[1];
    if (a.s[2] != b.s[2]) return a.s[2] < b.s[2];
    return a.num < b.num;
}

bool cmp2(team a, team b) {
    return a.num < b.num;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].s >> a[i].t;
        a[i].ans = "";
        a[i].num = i;
    }

    set <string> names;

    sort(a, a + n, cmp);
    fr(i, n) {
        int cur = i;
        while (cur + 1 < n && a[cur + 1].s.substr(0, 3) == a[i].s.substr(0, 3))
            cur++;
        //cout << i << " " << cur << endl;
        if (cur > i) {
            frab(j, i, cur + 1) {
                a[j].ans = (a[j].s.substr(0, 2) + a[j].t[0]);
                names.insert(a[j].ans);
            }
            i = cur;
        }
    }

    fr(i, n)
        fr(j, n)
            if (a[j].ans == "")
                if (names.count(a[j].s.substr(0, 3))) {
                    a[j].ans = a[j].s.substr(0, 2) + a[j].t[0];
                    names.insert(a[j].ans);
                }
                else if (names.count(a[j].s.substr(0, 2) + a[j].t[0])) {
                    a[j].ans = a[j].s.substr(0, 3);
                    names.insert(a[j].ans);
                }
    fr(i, n)
        if (a[i].ans == "") {
            a[i].ans = a[i].s.substr(0, 3);
            names.insert(a[i].ans);
        }
    if ((int)names.size() != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    sort(a, a + n, cmp2);
    fr(i, n)
        cout << a[i].ans << endl;
}
#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 3;

vector <int> a[N];
int cur[N];
vector <int> op;

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    //fill(cur, cur + n, -1);
    op.reserve(N);
    int ans = 0, last = 0;
    fr(i1, q) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            int x;
            scanf("%d", &x);
            op.pb(x);
            a[x].pb(op.size() - 1);
            ans++;
        }
        if (typ == 2) {
            int x;
            scanf("%d", &x);
            //for (int i = cur[x]; i < a[x].size(); i++)
            ans -= ((int)a[x].size() - cur[x]);
            cur[x] = a[x].size();
        }
        if (typ == 3) {
            int t;
            scanf("%d", &t);
            for (int i = last; i < t; i++) {
                int x = op[i];
                if (cur[x] < a[x].size() && i == a[x][cur[x]])
                    ans--, cur[x]++;
            }
            last = max(last, t);
        }
        printf("%d\n", ans);
    }
}
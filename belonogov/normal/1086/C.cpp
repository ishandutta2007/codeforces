#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int N = 1e6 + 10;

char ss[N];
char sa[N];
char sb[N];
int s[N];
int a[N];
int b[N];


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int k;
        scanf("%d", &k);
        scanf("%s%s%s", ss, sa, sb);
        int n = (int)strlen(ss);
        for (int i = 0; i < n; i++) {
            s[i] = ss[i] - 'a';
            a[i] = sa[i] - 'a';
            b[i] = sb[i] - 'a';
        }
        vector<bool> use(k);
        vector<int> perm(k, -1);
        vector<int> ans;
        function<void(int, bool, bool)> rec = [&](int pos, bool fa, bool fb)  {
            if (pos == n) {
                int cur = 0;
                ans = perm;
                for (int i = 0; i < k; i++) {
                    if (ans[i] == -1) {
                        for (;use[cur]; cur++);
                        ans[i] = cur;
                        cur++;
                    }
                }
                return;
            }


            if (perm[s[pos]] != -1) {
                if (fa && a[pos] > perm[s[pos]]) return;
                if (fb && b[pos] < perm[s[pos]]) return;
                rec(pos + 1, fa && a[pos] == perm[s[pos]], fb && b[pos] == perm[s[pos]]);
            }
            else {
                for (int i = 0; i < k; i++) {
                    if (use[i]) continue;
                    perm[s[pos]] = i;
                    use[i] = 1;
                    bool fail = 0;
                    if (fa && a[pos] > perm[s[pos]]) fail = 1;
                    if (fb && b[pos] < perm[s[pos]]) fail = 1;
                    if (!fail) {
                        rec(pos + 1, fa && a[pos] == perm[s[pos]], fb && b[pos] == perm[s[pos]]);
                    }

                    use[i] = 0;
                    perm[s[pos]] = -1;

                    if (!ans.empty()) {
                        return;
                    }
                }
            }


        };
        rec(0, true, true);
        if (ans.empty()) {
            puts("NO");
        }
        else {
            puts("YES");
            for (int i = 0; i < k; i++) {
                printf("%c", (char)('a' + ans[i]));
            }
            puts("");
        }

    }



    return 0;
}
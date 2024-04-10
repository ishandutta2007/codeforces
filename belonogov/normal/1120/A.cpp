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
const int N = 2e5 + 10;
const int ALF = 26;

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int m, k, n, s;
    scanf("%d%d%d%d", &m, &k, &n, &s);
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    map<int,int> need, have;
    for (int i = 0; i < s; i++) {
        int x;
        scanf("%d", &x);
        need[x]++;
    }
    int cnt_rem = m - k * n;

    int cur = 0;
    int full = 0;
    vector<int> answer;
    bool good = 0;
    for (int i = 0; i < m; i++) {
        for (; full < sz(need) && cur < m; cur++) {
            if (need.count(a[cur]))  {
                full -= have[a[cur]] >= need[a[cur]];
                have[a[cur]]++;
                full += have[a[cur]] >= need[a[cur]];
            }
        }
        if (full == sz(need)) {
            int g = i % k;
            int L = i - g;
            int R = L + k;
            if (cur <= R)  {
                good = 1;
                break;
                // ok
            }
            else {
                if (cur - R <= cnt_rem) {
                    int gg = cur - R;
                    good = 1;
                    for (int j = L; j < i; j++) {
                        answer.pb(j);
                        if ((int)answer.size() >= gg) break;
                    }
                    if ((int)answer.size() >= gg) break;
                    auto tmp = need;
                    for (int j = i; j < cur; j++) {
                        if (tmp[a[j]] == 0) {
                            answer.pb(j);
                        }
                        else {
                            tmp[a[j]]--;
                        }
                        if ((int)answer.size() >= gg) break;
                    }
                    break;
                }
            }
        }
        if (need.count(a[i])) {
            full -= have[a[i]] >= need[a[i]];
            have[a[i]]--;
            full += have[a[i]] >= need[a[i]];
        }
    }


    if (good) {
        printf("%d\n", (int)answer.size());
        for (auto x: answer) {
            printf("%d ", x + 1);
        }
        puts("");
    }
    else {
        puts("-1");
    }



#ifdef HOME
#endif
}
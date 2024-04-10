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



int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int answer = 0;
    vector<set<pair<int,int>>> dp(n);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        //db2(v, u);

        auto it = dp[v].lower_bound({w, -1});
        int have = 0;
        if (it != dp[v].begin()) {
            it--; 
            assert(it->F < w);
            have = it->S;
        }
        have++;

        it = dp[u].lower_bound({w + 1, -1});
        if (it != dp[u].begin()) {
            it--;
            assert(it->F <= w);
            if (it->S >= have) {
                continue;
            }
        }
        answer = max(answer, have);
        dp[u].insert({w, have});
        //it++;
        for (;;) {
            it = dp[u].lower_bound({w, have});
            assert(it != dp[u].end());
            it++;
            if (it == dp[u].end()) break;
            if (it->S <= have) {
                dp[u].erase(it);
            }
            else {
                break;
            }
        }
    }  


    cout << answer << endl;


    return 0;
}
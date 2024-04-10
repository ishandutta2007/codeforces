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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int tt = 0; tt < 2; tt++) {
        for (int j = 0; j < m; j++) {
            int who = -1;
            for (int i = 0; i < n; i++) {
                if (s[i][j] == '#' && who == -1) {
                    who = i;
                }
                if (s[i][j] == '#') {
                    if (s[i] != s[who]) {
                        puts("No");
                        return 0;
                    }
                }
            }


        }


        vector<string> b(m, string(n, ' '));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = s[i][j];
            }
        }
        swap(n, m);
        s = b;
    }

    puts("Yes");





    return 0;
}
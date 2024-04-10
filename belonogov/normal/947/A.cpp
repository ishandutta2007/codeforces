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
    int x;
    scanf("%d", &x);
    vector<int> jump(x + 1);
    for (int i = 3; i <= x; i++) {
        int mx = 1;
        int f = i;
        bool flag = 0;
        for (int j = 2; j * j <= f; j++) {
            if (f % j == 0) {
                mx = max(mx, j);
                flag = 1;
                for (; f % j == 0; f /= j);
            }
        }
        if (f > 1 && flag) {
            mx = max(mx, f);
        }
        jump[i] = mx;
    }
    int l = x - (jump[x] - 1);

    int answer = INF;
    for (int i = l; i <= x; i++) {
        answer = min(answer, i - (jump[i] - 1));
    }

    cout << answer << endl;



















    return 0;
}
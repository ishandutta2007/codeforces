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
    int n, u;
    scanf("%d%d", &n, &u);
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",  &e[i]);
    }
    int cur = 0;
    dbl answer = -1;
    for (int i = 0; i < n; i++) {
        for (; cur < n && e[cur] - e[i] <= u; cur++);
        if (cur - i >= 3) {
            answer = max(answer, (e[cur - 1] - e[i + 1]) * 1.0 / (e[cur - 1] - e[i]));
        }
    }
    if (answer == -1) {
        puts("-1");
    }
    else {
        printf("%.17f\n", answer);
    }





    return 0;
}
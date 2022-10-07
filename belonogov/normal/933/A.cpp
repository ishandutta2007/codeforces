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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",  &a[i]);
        a[i]--;
    }
    int cnt1 = 0;
    for (auto x: a) cnt1 += x;

    int cnt1L = 0;
    int answer = 0;
    for (int l = 0; l <= n; l++) {
        int cntZeroL = l - cnt1L;
        int cntOneR = cnt1 - cnt1L;
        int mxLeft = 0;
        int mxRight = 0;
        int bal = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (a[i] == 1) {
                bal++;
            }
            else {
                bal--;
            }
            mxLeft = max(mxLeft, bal);
        }
        bal = 0;
        for (int i = l; i < n; i++) {
            if (a[i] == 0) {
                bal++;
            }
            else {
                bal--;
            }
            mxRight = max(mxRight, bal);
        }

//        db3(l, cntZeroL, cntOneR);
//        db2(mxLeft, mxRight);
        answer = max(answer, cntZeroL + cntOneR + mxLeft + mxRight);
        if (l < n && a[l] == 1) {
            cnt1L++;
        }
    }



    cout << answer << endl;


    return 0;
}
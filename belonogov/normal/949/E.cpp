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
        scanf("%d", &a[i]);
    }
    vector<int> st;
    vector<int> answer(20, -1);
    bool flag = 0;


    function<void(int, vector<int>)> rec = [&](int pos, vector<int> b) {
//        dbv(st);
        if (st.size() >= answer.size()) return;
        if (b.empty()) {
            if (st.size() < answer.size() || flag) {
                answer = st;
                flag = 1;
            }
            return;
        }
        for (int cof = -1; cof <= 1; cof += 2) {
            int x = pw(pos) * cof;
            vector<int> tmp;
            vector<int> c;
            bool ff = 0;
            for (auto y: b) {
                if (y & pw(pos)) {
                    y -= x;
                    ff = 1;
                }
                if (y != 0) {
                    c.pb(y);
                }
            }
            sort(all(c));
            c.resize(unique(all(c)) - c.begin());
            if (ff) {
                st.pb(x);
            }
            rec(pos + 1, c);
            if (ff) {
                st.pop_back();
            }
        }
    };

    rec(0, a);



    cout << answer.size() << endl;
    for (auto x: answer) {
        cout << x << " ";
    }
    cout << endl;



    return 0;
}
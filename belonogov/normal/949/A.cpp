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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> answer;
    set<int> one;
    set<int> zero;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (one.empty()) {
                answer.pb(vector<int>());
                answer.back().pb(i);
                zero.insert(answer.size() - 1);
            }
            else {
                int id = *one.begin();
                one.erase(id);
                answer[id].pb(i);
                zero.insert(id);
            }
        }
        else {
            if (zero.empty()) {
                puts("-1");
                return 0;
            }
            else {
                int id = *zero.begin();
                zero.erase(id);
                answer[id].pb(i);
                one.insert(id);
            }
        }
    }

    if (!one.empty()) {
        puts("-1");
        return 0;
    }
    cout << answer.size() << endl;
    for (auto v: answer) {
        printf("%d ", sz(v));
        for (auto x: v) {
            printf("%d ", x + 1);
        }
        puts("");
    }






    return 0;
}
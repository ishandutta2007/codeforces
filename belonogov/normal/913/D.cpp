#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;

struct Task {
    int a, t, id;
};


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, T;
    scanf("%d%d", &n, &T);   
    vector<Task> task(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &task[i].a, &task[i].t);
        task[i].id = i;
    }
    int l = 0; 
    int r = n + 1;
    vector<int> answer;
    sort(all(task), [](Task A, Task B) {
                return A.t < B.t;
            });

    auto check = [&](int k) {
        vector<pair<int,int>> b;
        ll sum = 0;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (task[i].a >= k && sz(tmp) < k) {
                sum += task[i].t;
                tmp.pb(task[i].id);
            }
        }
        if (sum <= T && sz(tmp) == k) {
            answer = tmp;
            return 1;
        }
        else {
            return 0;
        }
    };

    while (r - l > 1) {
        if (check((l + r) / 2)) {
            l = (l + r) / 2;
        }
        else {
            r = (l + r) / 2;
        }
    }

    assert(sz(answer) == l);
    cout << l << endl;
    cout << l << endl;
    for (auto x: answer) {
        cout << x + 1 << " ";
    }
    cout << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}
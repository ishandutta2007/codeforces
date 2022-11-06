#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int main() {
    init_cin
    int n;
    cin >> n;
    priority_queue<int> q;
    vector<pair<string, int> > ans;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            int x;
            cin >> x;
            q.push(-x);
            ans.push_back({s, x});
        } else if (s == "removeMin") {
            int x = rand();
            if (q.empty()) {
                ans.push_back({"insert", x});
                q.push(x);
            }
            q.pop();
            ans.push_back({s, x});
        } else {
            int x;
            cin >> x;
            while (!q.empty() && -q.top() < x) {
                ans.push_back({"removeMin", -1});
                q.pop();
            }

            if (q.empty() || -q.top() != x) {
                ans.push_back({"insert", x});
                q.push(-x);
            }

            ans.push_back({s, x});
        }
    }

    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first;
        if (i.first != "removeMin") {
            cout << " " << i.second;
        }
        cout << "\n";
    }

    return 0;
}
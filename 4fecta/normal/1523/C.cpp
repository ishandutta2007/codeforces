#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int n, t, a[MN];
map<vector<int>, int> s;

void print(const vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        printf("%d", v[i]);
        if (i < v.size() - 1) printf(".");
        else printf("\n");
    }
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> path;
        path.push_back(0);
        for (int i = 1; i <= n; i++) {
            //path = path.substr(0, path.size() - 2);
            while (s[path] != a[i] - 1) {
                assert(path.size() >= 2);
                path.pop_back();
            }
            s[path] = a[i];
            path.push_back(a[i]);
            print(path);
        }
        s.clear();
    }

    return 0;
}
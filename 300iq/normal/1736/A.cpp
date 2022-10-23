#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>

#define x _x
#define y _y

using namespace std;

mt19937 rnd(228);

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i =0 ; i < n; i++) cin >> a[i];
        vector <int>b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        int ok = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) ok++;
        }
        map <int, int> cnt;
        for (int i = 0; i < n; i++) cnt[a[i]]++;
        for (int i = 0; i < n; i++) cnt[b[i]]--;
        int ret = 0;
        for (auto c : cnt) {
            ret += abs(c.second);
        }
        cout << min(ok, 1 + ret / 2) << endl;
    }
}
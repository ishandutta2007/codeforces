#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector <pair <int, int>> pa, pb;
        for (int i = 0; i < n / 2; ++i) {
            int pi = n - i - 1;
            pa.emplace_back(min(a[i], a[pi]), max(a[i], a[pi]));
            pb.emplace_back(min(b[i], b[pi]), max(b[i], b[pi]));
        }
        sort(pa.begin(), pa.end());
        sort(pb.begin(), pb.end());
        if (pa == pb && (n % 2 == 0 || a[n / 2] == b[n / 2])) cout << "yes\n";
        else cout << "no\n";
    }
}
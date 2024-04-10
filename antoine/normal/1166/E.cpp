#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;


bool intersect(const vector<int> &v1, const vector<int> &v2) {
    static vector<int> v(12345);
    auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    return it != v.begin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m);
    for (vector<int> &v:a) {
        int k;
        cin >> k;
        v.resize(k);
        for (int &x: v)
            cin >> x;
        sort(v.begin(), v.end());
    }

    for (vector<int> &v1 : a)
        for (vector<int> &v2:a)
            if (!intersect(v1, v2)) {
                cout << "impossible";
                return 0;
            }
    cout << "possible";
    return 0;
}
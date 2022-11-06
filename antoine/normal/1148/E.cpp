#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    vector<int> a(n), b(n), indexes(n);
    for (int &x:a) cin >> x;
    for (int &x:b) cin >> x;

    {
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; ++i)
            temp[i] = {a[i], i};
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; ++i) {
            a[i] = temp[i].first;
            indexes[i]= temp[i].second;
        }
    }

    sort(b.begin(), b.end());

    vector<array<int, 3>> res;


    for(int i = 0, j = 0; i < n; ++i) {
        if(a[i] > b[i]) {
            cout << "NO";
            return 0;
        }
        j = max(j, i + 1);
        while(a[i] < b[i]) {
            while(j < n && a[j] <= b[j])
                ++j;
            if(j >= n) {
                cout << "NO";
                return 0;
            }
            assert(b[i] <= b[j]);
            const int d = min(b[i] - a[i], a[j] - b[j]);
            a[i] += d;
            a[j] -= d;
            res.push_back({i, j, d});
        }
    }

    for(int i = 0; i < n; ++i)
        assert(a[i] == b[i]);
    cout << "YES\n" << res.size() << endl;
    for(auto &&p  : res)
        cout << indexes[p[0]] + 1 << ' ' << indexes[p[1]] + 1 << ' ' << p[2] << '\n';
    return 0;
}
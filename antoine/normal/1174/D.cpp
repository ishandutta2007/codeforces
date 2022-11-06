#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int k, X;
    cin >> k >> X;

    set<int> s;
    for(int i = 0; i < (1 << k); ++i)
        s.insert(i);


    s.erase(0);
    s.erase(X);

    vector<int> a;
    while(!s.empty()) {
        a.push_back(*s.begin());
        s.erase(*s.begin() ^ X);
        s.erase(s.begin());
    }

    adjacent_difference(a.begin(), a.end(), a.begin(), [](const int x, const int y) {
        return x^y;
    });
    cout << a.size() << endl;
    for(int x : a)
        cout << x << ' ';

    return 0;
}
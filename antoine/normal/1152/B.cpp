#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    for (int i = 0; i < 30; ++i) {
        mp[(1 << i) - 1] = i;
    }

    int x;
    cin >> x;
    vector<int> res;
    int t = 0;
    for (; !mp.count(x); ++t) {
        if (t & 1)
            ++x;
        else {
            if (x & 1) {
                for (int i = 30; i >= 0; --i)
                    if ((1 << i) < x && !(x & (1 << i))) {
                        res.push_back(i + 1);
                        break;
                    }
            } else {
                int y = x & (x - 1);
                y = x ^ y;
                --y;
                res.push_back(mp.at(y));
            }


            x ^= (1 << res.back()) - 1;
        }
    }


    cout << t << endl;
    for (
        int x
            : res)
        cout << x <<
             ' ';
    return 0;
}
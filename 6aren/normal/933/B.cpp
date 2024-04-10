#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t p;
    int k;
    cin >> p >> k;

    vector<int> digits;
    while (p) {
        digits.push_back(p % k);
        p /= k;
    }    

    vector<int> res;
    int rem = 0;
    for (int i = 0; i < digits.size(); i++) {
        if (i % 2 == 0) {
            res.push_back((digits[i] + rem) % k);
            rem = (digits[i] + rem) / k;
        } else {
            int foo = digits[i] + rem;
            res.push_back((2 * k - foo) % k);
            rem = (foo % k == 0 ? foo / k : foo / k + 1);
        }
    }
    while (rem != 0) {
        digits.push_back(0);
        int i = digits.size() - 1;
        if (i % 2 == 0) {
            res.push_back((digits[i] + rem) % k);
            rem = (digits[i] + rem) / k;
        } else {
            int foo = digits[i] + rem;
            res.push_back((2 * k - foo) % k);
            rem = (foo % k == 0 ? foo / k : foo / k + 1);
        }
    }
    // reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int e : res) cout << e << ' ';
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

string add1(string s) {
    int carry = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
        carry += s[i] - '0';
        s[i] = '0' + (carry & 1);
        carry >>= 1;
    }
    assert(!carry);
    return s;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int  n;
    string l, r;
    cin >> n >> l >> r;
    if(n > 1 && l[0] == '0') {
        cout << string(n, '1');
        return 0;
    }
    if(r.back() == '0' && r != l && add1(l) != r) {
        cout << r.substr(0, n-1) << '1';
    } else
        cout << r;
    return 0;
}
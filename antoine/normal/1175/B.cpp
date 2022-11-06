#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    ll coeff = 1;
    ll res = 0;
    const ll mx = (1LL << 32) - 1;

    stack<int> st;

    int skips = 0;

    while (t--) {
        string str;
        cin >> str;
        if (str == "add") {
            if (skips) {
                cout << "OVERFLOW!!!";
                return 0;
            }
            res += coeff;
        } else if (str == "end") {
            if (skips)
                --skips;
            else {
                coeff /= st.top();
                st.pop();
            }
        } else {
            assert(str == "for");
            int x;
            cin >> x;
            if (coeff > mx)
                ++skips;
            else {
                coeff *= x;
                st.push(x);
            }
        }
        if (res > mx) {
            cout << "OVERFLOW!!!";
            return 0;
        }
    }
    cout << res;
    return 0;
}
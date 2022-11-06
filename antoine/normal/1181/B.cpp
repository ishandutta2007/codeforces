#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int n;
string s;

string add(const string &&s1, const string &&s2) {
    string res;
    int carry = 0;
    for (int i = 0; i < s1.size() || i < s2.size() || carry; ++i) {
        if (i < s1.size()) carry += *(s1.rbegin() + i) - '0';
        if (i < s2.size()) carry += *(s2.rbegin() + i) - '0';
        res += char('0' + carry % 10);
        carry /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}


string f(int i, bool left) {
    i = max(0, i);
    i = min(n - 2, i);
    while (0 <= i && i + 1 < n && s[i + 1] == '0')
        left ? --i : ++i;
    if (0 <= i && i + 1 < n)
        return add(s.substr(0, i + 1), s.substr(i + 1));
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> s;

    string ans = "";

    for (int i = max(0, n / 2 - 3); i < n / 2 + 3; ++i) {
        for (bool left : {false, true}) {
            string res = f(i, left);
            if (res == "")
                continue;
            if (ans == "" || ans.size() > res.size() || (ans.size() == res.size() && ans > res))
                ans = res;
        }
    }
    cout << ans;

    return 0;
}
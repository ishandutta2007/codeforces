#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n, k;
string get1(string a)
{
    bool ok = true;
    bool eq = true;
    string ret;

    for (int i = 0; i < n; ++i) {
        if (i < k) {
            ret.push_back(a[i]);
        } else {
            ret.push_back(ret[i - k]);
        }

        if (eq && ret[i] < a[i]) {
            ok = false;
        }

        if (eq && ret[i] > a[i]) {
            eq = false;
        }
    }

    if (!ok) {
        ret.push_back(ret[n - k]);
    }

    return ret;
}

string get2(string a)
{
    string ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(a[i]);
    }

    for (int i = k - 1; i >= 0; --i) {
        if (ret[i] < '9') {
            ret[i]++;
            break;
        }

        ret[i] = '0';
    }

    if (ret[0] == '0') {
        return a + a + a;
    }

    for (int i = k; i < n; ++i) {
        ret.push_back(ret[i - k]);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    string s;
    cin >> s;

    string s1 = get1(s);
    string s2 = get2(s);

    if (s1.size() < s2.size()) {
        cout << s1.size() << endl;
        cout << s1 << endl;
    } else if (s2.size() < s1.size()) {
        cout << s2.size() << endl;
        cout << s2 << endl;
    } else {
        cout << s1.size() << endl;
        cout << (s1 < s2 ? s1 : s2) << endl;
    }

    return 0;
}
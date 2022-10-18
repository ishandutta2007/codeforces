#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42, logn = 20;
const int inf = 1e9;

int bpow(int x, int n, int m) {
    return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

string lcp(string a, string b) {
    string t;
    for(size_t i = 0; i < a.size() && i < b.size(); i++) {
        if(a[i] == b[i]) {
            t += a[i];
        } else {
            break;
        }
    }
    return t;
}

string combine(string a, string b) {
    if(a == "-1") {
        return b;
    } else return lcp(a, b);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    string t[n];
    string A = "", B = "";
    string pr = "-1", sf = "-1";
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        int m = t[i].size();
        int L = 0, R = m - 1;
        while(L < m && s[i][L] == t[i][L]) {
            L++;
        }
        while(R >= 0 && s[i][R] == t[i][R]) {
            R--;
        }
        if(L != m) {
            string a = s[i].substr(L, R - L + 1);
            string b = t[i].substr(L, R - L + 1);
            if(A.empty() || (a == A && b == B)) {
                A = a;
                B = b;
                string aa = s[i].substr(0, L);
                aa = string(rall(aa));
                string bb = s[i].substr(R + 1);
                pr = combine(pr, aa);
                sf = combine(sf, bb);
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    A = string(rall(pr)) + A + sf;
    B = string(rall(pr)) + B + sf;
    for(int i = 0; i < n; i++) {
        size_t lol = s[i].find(A);
        if(lol != string::npos) {
            s[i].replace(lol, A.size(), B);
        }
        if(s[i] != t[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << A << '\n' << B << endl;
    return 0;
}
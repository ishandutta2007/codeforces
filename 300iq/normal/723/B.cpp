#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
        while (i < n && (s[i] == '_' || s[i] == ')') && s[i] != '(') i++; 
        int ans = 0;
        if (i < n && s[i] == '(') {
            if (i < n - 1 && s[i + 1] != '_' && s[i + 1] != ')') rs++;
            while (i < n && s[i] != ')') {
                if (s[i] == '_' && i < n - 1 && s[i + 1] != '_' && s[i + 1] != ')') rs++;
                i++;
            }
        } else if (i < n) {
            while (i < n && s[i] != '_' && s[i] != '(') i++, ans++;
            res = max(res, ans);
        }
        i--;
    }
    printf("%d %d\n", res, rs);
}
#include <bits/stdc++.h>

using namespace std;

int n, q;
unordered_map <string, char> g;
int ans = 0;

bool check(string s) {
    string f = s;
    int sz = (int) s.size();
    int st = 1;
    while (sz > 1) {
        string gg = "";
        gg += s[st - 1];
        gg += s[st];
        if (g[gg] >= 'a' & g[gg] <= 'f') {
            sz--;
            s[st++] = g[gg];
        } else {
            return false;
        }
    }
    return s.back() == 'a';
}

void gen(string s) {
    if (s.length() == n) {
        ans += check(s);
    } else {
        for (int z = 'a'; z <= 'f'; z++) {
            string f = s;
            f += (char) z;
            gen(f);
        }
    }
}

int main() {
    cin >> n >> q;
    string a;
    char b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        g[a] = b;
    }
    gen("");
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 5005;

vector<string> split(string s) {
    vector<string> res;    
    
    string tmp;
    for (char ch : s) {
        if (ch == ' ' || ch == '\n') {
            if (tmp.size()) {
                res.pb(tmp);
                tmp.clear();
            } 
        }
        else tmp.pb(ch);
    }
    if (tmp.size()) res.pb(tmp);
    return res;
}

int n, m;
vector<string> var[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> m;
    map<string, int> mp;
    string res_max(m, 0);
    string res_min(m, 0);
    string foo;
    getline(cin, foo);
    for (int i = 1; i <= n; i++) {
        string t;
        getline(cin, t);
        var[i] = split(t);
        mp[var[i][0]] = i;
        if (var[i].size() == 5) {
            if (var[i][2] == "?") swap(var[i][2], var[i][4]);
        }
    }

    for (int i = 0; i < m; i++) {
        // 0
        for (int j = 1; j <= n; j++) {
            if (var[j].size() == 3) {
                string t = var[j][2];
                ans[j] = (t[i] == '1');
            } else {
                string t = var[j][2];
                if (t == "?") ans[j] = 0;
                else {
                    bool ch = ans[mp[t]];
                    string op = var[j][3];
                    if (var[j][4] == "?") {
                        if (op == "AND") ans[j] = 0;
                        else ans[j] = ch; 
                    } else {
                        bool ch2 = ans[mp[var[j][4]]];
                        if (op == "AND") ans[j] = (ch and ch2);
                        else if (op == "OR") ans[j] = (ch or ch2);
                        else if (op == "XOR") ans[j] = (ch xor ch2);
                    }
                }
            }
        }
        int cnt0 = 0;
        for (int j = 1; j <= n; j++) if (ans[j] == 1) cnt0++;

        // 1
        for (int j = 1; j <= n; j++) {
            if (var[j].size() == 3) {
                string t = var[j][2];
                ans[j] = (t[i] == '1');
            } else {
                string op = var[j][3];
                string t = var[j][2];
                if (t == "?") {
                    if (op == "AND" || op == "OR") ans[j] = 1;
                    else ans[j] = 0;
                } else {
                    bool ch = ans[mp[t]];
                    if (var[j][4] == "?") {
                        if (op == "OR") ans[j] = 1;
                        else if (op == "AND") ans[j] = ch;
                        else ans[j] = 1 - ch; 
                    } else {
                        bool ch2 = ans[mp[var[j][4]]];
                        if (op == "AND") ans[j] = (ch and ch2);
                        else if (op == "OR") ans[j] = (ch or ch2);
                        else if (op == "XOR") ans [j] = (ch xor ch2);
                    }
                }
            }
        }
        int cnt1 = 0;
        for (int j = 1 ; j <= n ; j++) if (ans[j] == 1) cnt1++;
        
        if (cnt1 > cnt0) res_max[i] = '1', res_min[i] = '0';
        else if (cnt1 == cnt0) res_max[i] = res_min[i] = '0';
        else res_max[i] = '0', res_min[i] = '1';
    }
    cout << res_min << endl;
    cout << res_max;

    return 0;
}
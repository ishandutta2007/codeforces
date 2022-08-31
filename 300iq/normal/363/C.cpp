#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair

bool kill[200000];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int n = (int) s.size();
    vector <int> eq(n);
    string p = "";
    int cnt = 0;
    char prev = '-';
    for (int i = 0; i < n; i++) {
        if (s[i] == prev) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt < 2) {
            p += s[i];
        }
        prev = s[i];
    }
    memset(kill, 0, sizeof kill);
    n = (int) p.size();
    for (int i = 0; i + 3 < n; i++) {
        if (!kill[i] && !kill[i + 1] && !kill[i + 2] && !kill[i + 3] && p[i] == p[i + 1] && p[i + 2] == p[i + 3]) {
            kill[i + 3] = 1;
        }
    }
    for (int i = 0; i < (int) p.size(); i++) {
        if (!kill[i]) {
            cout << p[i];
        }   
    }
    cout << endl;
}
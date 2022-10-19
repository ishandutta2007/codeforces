#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1000005;

int n;
string s, t;
int a[N], b[N];
int pref1[N], pref0[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    set<int> pos;
    set<int> pos0;
    set<int> pos1;
    
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] == 1) {
            pos.insert(i);
            if (a[i]) pos0.insert(i);
            else pos1.insert(i);
        }
    }

    if (pos0.size() != pos1.size()) return cout << -1, 0;

    while (!pos.empty()) {
        int t = *pos.begin();
        pos.erase(t);
        int nx = 0;
        if (a[t] == 1) {
            nx = *pos1.lower_bound(t);
            pos1.erase(nx);
            pref0[t]++;
            pref0[nx + 1]--;
        } else {
            nx = *pos0.lower_bound(t);
            pos0.erase(nx);
            pref1[t]++;
            pref1[nx + 1]--;
        }
        pos.erase(nx);
    }

    int mx0 = 0, mx1 = 0;

    for (int i = 1; i <= n; i++) {
        pref0[i] += pref0[i - 1];
        pref1[i] += pref1[i - 1];
        mx0 = max(mx0, pref0[i]);
        mx1 = max(mx1, pref1[i]);
    }

    cout << mx0 + mx1;

    return 0;
}
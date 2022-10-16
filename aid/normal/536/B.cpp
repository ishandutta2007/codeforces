#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7, SIGMA = 26;
int a[MAXN], z[MAXN], b[MAXN];
vector<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    string p;
    cin >> n >> m >> p;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    int len = p.length();
    for(int i = 1; i < m; i++)
        if(a[i] - a[i - 1] < len)
            q.push_back(a[i] - a[i - 1]);
    for(int i = 1, l = 0, r = 0; i < len; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < len && p[z[i]] == p[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for(size_t i = 0; i < q.size(); i++)
        if(q[i] + z[q[i]] < len) {
            cout << 0 << '\n';
            return 0;
        }
    for(int i = 0; i < m; i++) {
        b[a[i]]++;
        b[a[i] + len]--;
    }
    int bal = 0, ans = 1;
    for(int i = 0; i < n; i++) {
        bal += b[i];
        if(!bal)
            ans = (long long)ans * SIGMA % MOD;
    }
    cout << ans << '\n';
    return 0;
}
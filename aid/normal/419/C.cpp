#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 300 * 1000 + 5;
int d[MAXN], s[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    for(int i = 0; i < n; i++)
        s[d[i]]++;
    for(int i = n - 1; i >= 0; i--)
        s[i] += s[i + 1];
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int q = s[max(p - d[i], 0)];
        if(d[i] >= p - d[i])
            q--;
        map<int, int> mp;
        for(size_t j = 0; j < g[i].size(); j++)
            if(d[g[i][j]] >= p - d[i]) {
                if(mp[g[i][j]] == 0)
                    q--;
                mp[g[i][j]]++;
            }
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
            if(d[it->first] - it->second >= p - d[i])
                q++;
        ans += q;
    }
    cout << ans / 2 << '\n';
    return 0;
}
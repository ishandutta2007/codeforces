#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

const int MAXN = 2005;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    long long sa = 0;
    for(int i = 0; i < n; i++)
        sa += a[i];
    long long sb = 0;
    for(int i = 0; i < m; i++)
        sb += b[i];
    vector< pair<int, int> > ans;
    long long best = llabs(sa - sb);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(llabs((sa - a[i] + b[j]) - (sb - b[j] + a[i])) < best) {
                best = llabs((sa - a[i] + b[j]) - (sb - b[j] + a[i]));
                ans.clear();
                ans.push_back(make_pair(i, j));
            }
    map<long long, pair<int, int> > mp;
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            mp[2ll * (b[i] + b[j])] = make_pair(i, j);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            long long d = sa - sb - 2ll * (a[i] + a[j]);
            map<long long, pair<int, int> >::iterator it = mp.lower_bound(-d);
            if(it != mp.end() && d + it->first < best) {
                best = d + it->first;
                ans.clear();
                ans.push_back(make_pair(i, it->second.first));
                ans.push_back(make_pair(j, it->second.second));
            }
            if(it != mp.begin()) {
                it--;
                if(-d - it->first < best) {
                    best = -d - it->first;
                    ans.clear();
                    ans.push_back(make_pair(i, it->second.first));
                    ans.push_back(make_pair(j, it->second.second));
                }
            }
        }
    cout << best << '\n' << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    return 0;
}
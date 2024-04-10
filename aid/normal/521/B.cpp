#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 100 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 9;
int bad[MAXN];
pair<int, int> a[MAXN];
vector<int> up[MAXN], down[MAXN];
map<pair<int, int>, int> mp;
set<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < n; i++)
        mp[a[i]] = i;
    for(int i = 0; i < n; i++) {
        for(int j = -1; j <= 1; j++)
            if(mp.find(make_pair(a[i].first + j, a[i].second + 1)) != mp.end())
                up[i].push_back(mp[make_pair(a[i].first + j, a[i].second + 1)]);
        for(int j = -1; j <= 1; j++)
            if(mp.find(make_pair(a[i].first + j, a[i].second - 1)) != mp.end())
                down[i].push_back(mp[make_pair(a[i].first + j, a[i].second - 1)]);
    }
    for(int i = 0; i < n; i++)
        if(down[i].size() == 1)
            bad[down[i][0]]++;
    for(int i = 0; i < n; i++)
        if(!bad[i])
            st.insert(i);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int dig;
        if(i & 1) {
            dig = *st.begin();
            st.erase(st.begin());
        }
        else {
            set<int>::iterator it = st.end();
            it--;
            dig = *it;
            st.erase(it);
        }
        ans = ((long long)ans * n + dig) % MOD;
        for(size_t j = 0; j < up[dig].size(); j++) {
            int x = up[dig][j];
            for(size_t k = 0; k < down[x].size(); k++)
                if(down[x][k] == dig) {
                    swap(down[x][k], down[x].back());
                    down[x].pop_back();
                    break;
                }
            if(down[x].size() == 1) {
                if(!bad[down[x][0]])
                    st.erase(down[x][0]);
                bad[down[x][0]]++;
            }
        }
        for(size_t j = 0; j < down[dig].size(); j++) {
            int x = down[dig][j];
            for(size_t k = 0; k < up[x].size(); k++)
                if(up[x][k] == dig) {
                    swap(up[x][k], up[x].back());
                    up[x].pop_back();
                    break;
                }
            if(down[dig].size() == 1) {
                bad[x]--;
                if(!bad[x])
                    st.insert(x);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
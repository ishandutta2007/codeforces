#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 50 * 1000 + 5, SIGMA = 27,
    MAXH = 1000 * 1000 + 5, MAXQ = 100 * 1000 + 5;
pair<int, int> qq[MAXQ], qlen[MAXQ];
int ans[MAXQ];
string s;
vector<int> v[MAXH];
map<pair<int, int>, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        for(size_t j = 0; j < a.length(); j++)
            qq[i].first = qq[i].first * SIGMA + a[j] - 'a' + 1;
        for(size_t j = 0; j < b.length(); j++)
            qq[i].second = qq[i].second * SIGMA + b[j] - 'a' + 1;
        qlen[i] = make_pair(a.length(), b.length());
    }
    int n = s.length();
    for(int i = 0; i < n; i++) {
        int h = 0;
        for(int j = i; j < min(i + 4, n); j++) {
            h = h * SIGMA + s[j] - 'a' + 1;
            v[h].push_back(i);
        }
    }
    for(int i = 0; i < q; i++) {
        if(v[qq[i].first].empty() || v[qq[i].second].empty()) {
            ans[i] = -1;
            continue;
        }
        if(v[qq[i].first].size() > v[qq[i].second].size()) {
            swap(qq[i].first, qq[i].second);
            swap(qlen[i].first, qlen[i].second);
        }
        if(mp.find(make_pair(qq[i].first, qq[i].second)) != mp.end()) {
            ans[i] = mp[make_pair(qq[i].first, qq[i].second)];
            continue;
        }
        ans[i] = n;
        for(size_t j = 0; j < v[qq[i].first].size(); j++) {
            vector<int>::iterator it = lower_bound(v[qq[i].second].begin(),
                                                   v[qq[i].second].end(),
                                                   v[qq[i].first][j]);
            if(it != v[qq[i].second].end())
                ans[i] = min(ans[i], max(v[qq[i].first][j] + qlen[i].first,
                                         *it + qlen[i].second) -
                             v[qq[i].first][j]);
            if(it != v[qq[i].second].begin()) {
                it--;
                ans[i] = min(ans[i], max(v[qq[i].first][j] + qlen[i].first,
                                         *it + qlen[i].second) - *it);
            }
        }
        mp[make_pair(qq[i].first, qq[i].second)] = ans[i];
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}
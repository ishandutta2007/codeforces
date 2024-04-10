#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 300 * 1000 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    set<int> st;
    vector< pair<int, int> > ans;
    int l = 0;
    for(int i = 0; i < n; i++)
        if(st.find(a[i]) == st.end())
            st.insert(a[i]);
        else {
            ans.push_back(make_pair(l, i));
            l = i + 1;
            st.clear();
        }
    if(ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    ans.back().second = n - 1;
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    return 0;
}
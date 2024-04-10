#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(i + 1);
    vector<int> ans(n);
    for(int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        set<int>::iterator itl = st.lower_bound(l),
            itr = st.upper_bound(r);
        vector<int> v;
        for(; itl != itr; itl++)
            if(*itl != x) {
                ans[*itl - 1] = x;
                v.push_back(*itl);
            }
        for(size_t j = 0; j < v.size(); j++)
            st.erase(v[j]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
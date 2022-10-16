#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<char, int> a[MAXN];
char used[MAXN], ans[MAXN], ans1[MAXN];
set<int> st;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        ans[i] = true;
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second--;
        if(!used[a[i].second]) {
            used[a[i].second] = true;
            if(a[i].first == '-')
                st.insert(a[i].second);
        }
    }
    for(int i = 0; i < m; i++)
        if(a[i].first == '+') {
            if(st.empty())
                ans1[a[i].second] = true;
            else
                ans[a[i].second] = false;
            st.insert(a[i].second);
        }
        else {
            st.erase(a[i].second);
            if(!st.empty())
                ans[a[i].second] = false;
            else
                ans1[a[i].second] = true;
        }
    int k = 0, p = -1;
    for(int i = 0; i < n; i++)
        if(ans1[i]) {
            k++;
            p = i;
        }
    if(k > 1)
        for(int i = 0; i < n; i++)
            ans[i] = false;
    if(k == 1)
        for(int i = 0; i < n; i++)
            if(i != p)
                ans[i] = false;
    for(int i = 0; i < n; i++)
        if(ans[i] || !used[i])
            v.push_back(i);
    cout << v.size() << '\n';
    if(v.size() > 0) {
        for(size_t i = 0; i < v.size(); i++)
            cout << v[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
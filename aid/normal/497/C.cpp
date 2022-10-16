#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN], k[MAXN], ans[MAXN];
pair<int, pair<char, int> > p[3 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        p[i] = make_pair(a[i], make_pair(1, i));
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> d[i] >> k[i];
        p[n + 2 * i] = make_pair(c[i], make_pair(0, i));
        p[n + 2 * i + 1] = make_pair(d[i], make_pair(2, i));
    }
    sort(p, p + n + 2 * m);
    set< pair<int, int> > st;
    for(int i = 0; i < n + 2 * m; i++) {
        int id = p[i].second.second;
        if(p[i].second.first == 0)
            st.insert(make_pair(d[id], id));
        else if(p[i].second.first == 2)
            st.erase(make_pair(d[id], id));
        else {
            set< pair<int, int> >::iterator it =
                st.lower_bound(make_pair(b[id], -1));
            if(it == st.end()) {
                cout << "NO\n";
                return 0;
            }
            int segId = it->second;
            ans[id] = segId;
            k[segId]--;
            if(!k[segId])
                st.erase(it);
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}
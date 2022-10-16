#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<int, pair<int, int> > segs[MAXN];
pair<int, char> p[10 * MAXN];
set< pair<int, int> > st;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> segs[i].second.first >> segs[i].second.second >> segs[i].first;
    sort(segs, segs + m);
    int k = 0;
    for(int i = 0; i < m; i++) {
        int l = segs[i].second.first, r = segs[i].second.second, t = segs[i].first;
        int ll = l;
        set< pair<int, int> >::iterator
            itl = st.upper_bound(make_pair(l, -1)),
            itr = st.upper_bound(make_pair(r, -1));
        if(itl != st.begin()) {
            set< pair<int, int> >::iterator it = itl;
            it--;
            if(it->second > l) {
                l = it->second;
                ll = it->first;
                st.erase(it);
            }
        }
        while(itl != itr) {
            if(l < itl->first) {
                p[k++] = make_pair(t - l, 2);
                p[k++] = make_pair(t - itl->first, 0);
            }
            l = itl->second;
            set< pair<int, int> >::iterator del = itl;
            itl++;
            st.erase(del);
        }
        if(l < r) {
            p[k++] = make_pair(t - l, 2);
            p[k++] = make_pair(t - r, 0);
        }
        st.insert(make_pair(ll, max(l, r)));
    }
    for(int i = 0; i < n; i++) {
        cin >> p[k].first;
        p[k++].second = 1;
    }
    sort(p, p + k);
    int sum = 0, op = 0;
    for(int i = 0;i < k; i++) {
        if(i)
            sum += op * (p[i].first - p[i - 1].first);
        if(p[i].second == 0)
            op++;
        else if(p[i].second == 1)
            cout << sum << '\n';
        else
            op--;
    }
    return 0;
}
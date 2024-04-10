#include <iostream>
#include <set>

using namespace std;

const int MAXN = 300 * 1000 + 5;
set<int> st[MAXN];
set< pair<int, int> > stall;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int tt = 0;
    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        x--;
        if(t == 1) {
            st[x].insert(tt);
            stall.insert(make_pair(tt, x));
            tt++;
        }
        else if(t == 2) {
            for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++)
                stall.erase(make_pair(*it, x));
            st[x].clear();
        }
        else {
            while(!stall.empty() && stall.begin()->first <= x) {
                st[stall.begin()->second].erase(stall.begin()->first);
                stall.erase(stall.begin());
            }
        }
        cout << stall.size() << '\n';
    }
    return 0;
}
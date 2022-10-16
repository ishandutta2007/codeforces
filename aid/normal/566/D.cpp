#include <iostream>
#include <set>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int p[MAXN], ts[MAXN];

int get(int x) {
    return x == p[x]? x : p[x] = get(p[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(ts[x] < ts[y])
        swap(x, y);
    p[y] = x;
    ts[x] += ts[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        p[i] = i;
        ts[i] = 1;
    }
    set<int> st;
    for(int i = 0; i < n - 1; i++)
        st.insert(i);
    for(int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if(t == 1)
            unite(x, y);
        else if(t == 2) {
            while(true) {
                set<int>::iterator it = st.lower_bound(x);
                if(it == st.end() || *it >= y)
                    break;
                unite(*it, *it + 1);
                st.erase(it);
            }
        }
        else
            cout << (get(x) == get(y)? "YES" : "NO") << '\n';
    }
    return 0;
}
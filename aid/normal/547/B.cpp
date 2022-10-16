#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int p[MAXN], ts[MAXN];
pair<int, int> a[MAXN];

int get(int x) {
    return x == p[x]? x : p[x] = get(p[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x == y)
        return;
    if(ts[x] < ts[y])
        swap(x, y);
    ts[x] += ts[y];
    p[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater< pair<int, int> >());
    int len = 1;
    for(int i = 0; i < n; i++) {
        int val = a[i].first, pos = a[i].second;
        p[pos] = pos;
        ts[pos] = 1;
        if(pos && ts[pos - 1])
            unite(pos, pos - 1);
        if(pos < n && ts[pos + 1])
            unite(pos, pos + 1);
        int sz = ts[get(pos)];
        while(len <= sz) {
            cout << val << ' ';
            len++;
        }
    }
    cout << '\n';
    return 0;
}
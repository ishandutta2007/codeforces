#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define M 200100
#define long long long
#define mp make_pair
#define INF 1000000000
#define A 26
#define T 507

string s;
int n = 0;
pair<int, int> p[M];
map<pair<int, int>, int > ans;
set<pair<int, int> > ca;

int hah(int i, int len, const string &s) {
    int h = len;
    for (int j = i; j < i + len; ++j)
        h = (s[j] - 'a') + A * h;
    return h;
}

void read() {
    cin >> s;
    for (int i = 0; i < (int) s.length(); ++i)
        for (int j = 1; j <= 4 && i + j <= (int) s.length(); ++j)
            p[n++] = make_pair(hah(i, j, s), i);
    sort(p, p + n);
}

void bounds(int x, int &l, int &r) {
    l = (int) (lower_bound(p, p + n, make_pair(x, -1)) - p);
    r = (int) (lower_bound(p, p + n, make_pair(x, INF)) - p);
}

int ff(int x, int s) {
    return (int) (lower_bound(p, p + n, make_pair(x, s)) - p);
}

int fl(int x, int s) {
    return (int) (upper_bound(p, p + n, make_pair(x, s)) - p) - 1;
}

int get(int x, int y, int lenx, int leny) {
    int lx, rx, ly, ry;
    bounds(x, lx, rx);
    bounds(y, ly, ry);

    if (lx == rx || ly == ry)
        return -1;

    if (rx - lx > ry - ly)
        return get(y, x, leny, lenx);

    int ans = INF;

    for (int i = lx; i < rx; ++i) {
        int t = p[i].second;

        int v = ff(y, t);
        if (v < n && p[v].first == y)
            ans = min(ans, max(p[v].second + leny, t + lenx) - t);

        v = fl(y, t);
        if (v != -1 && p[v].first == y )
            ans = min(ans, max(p[v].second + leny, t + lenx) - p[v].second);
    }

    return ans;
}

int cou(int x) {
    int l, r;
    bounds(x, l, r);
    return r - l;
}

void kill() {
    

    int q;
    cin >> q;
    string a, b;



    for (int i = 0; i < q; ++i) {

        cin >> a >> b;
        int lenx = a.length();
        int leny = b.length();
        int x = hah(0, lenx, a);
        int y = hah(0, leny, b);
        if (x > y){
            swap(lenx, leny);
            swap(x, y);
        }

        
        int cx = cou(x);
        int cy = cou(y);


        if (cx >= T && cy >= T) {
            if (ca.find(make_pair(x, y)) == ca.end()) {
                ca.insert(make_pair(x, y));
                ans[make_pair(x, y)] = get(x, y, lenx, leny);
            }
            cout << ans[make_pair(x, y)] << "\n";
        }
        else
            cout << get(x, y, lenx, leny) << "\n";




    }
}



int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();
    

    return 0;
}
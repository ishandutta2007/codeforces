#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 500003;
const int MAXT = 1048576 + 7;

int next[MAXN << 1], dest[MAXN << 1];
int last[MAXN];

int m, n;
int x, y;
int l[MAXN], r[MAXN];

int root = 1;
int k;
int color[MAXT], empty[MAXT];

void dfs(int x, int p = -1)
{
    m++;
    l[x] = m;
    for (int i = last[x]; i; i = next[i])
    {
        int y = dest[i];
        if (y != p)
            dfs(y, x);
    }
    r[x] = m;
}

inline void pushing(int curr)
{
    if (color[curr])
    {
        color[(curr << 1) + 0] = color[(curr << 1) + 1] = color[curr];
        color[curr] = 0;
    }
}

void modify(int curr, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R)
    {
        color[curr] = v;
        return;
    }
    pushing(curr);

    int c = (l + r) / 2;
    if (L <= c)
        modify((curr << 1) + 0, l, c, L, R, v);
    if (c < R)
        modify((curr << 1) + 1, c + 1, r, L, R, v);
}

int get(int curr, int l, int r, int i)
{
    if (l == r)
    {
        return color[curr];
    }
    pushing(curr);
    int c = (l + r) / 2;
    return i <= c? get((curr << 1) + 0, l, c, i) : get((curr << 1) + 1, c + 1, r, i);
}

int eget(int curr, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return empty[curr];
    int c = (l + r) / 2;
    int res = 0;
    if (L <= c)
        res = max(res, eget((curr << 1) + 0, l, c, L, R));
    if (c < R)
        res = max(res, eget((curr << 1) + 1, c + 1, r, L, R));
    return res;
}

void emodify(int curr, int l, int r, int i, int v)
{
    empty[curr] = v;
    if (l == r)
        return;

    int c = (l + r) / 2;
    if (i <= c)
        emodify((curr << 1) + 0, l, c, i, v);
    else
        emodify((curr << 1) + 1, c + 1, r, i, v);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        
        dest[i] = y;
        next[i] = last[x];
        last[x] = i;
        
        dest[i + n] = x;
        next[i + n] = last[y];
        last[y] = i + n;
    }
    
    dfs(1);
/*    
    for (int i = 1; i <= n; i++)
        cout << i << " " << l[i] << " " << r[i] << endl;
//*/    
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int c, x;
        cin >> c >> x;
        //cout << c << " " << x << endl;
        switch (c)
        {
            case 1:
//                cout << l[x] << " " << r[x] << " " << i << endl;
                modify(root, 1, m, l[x], r[x], i);
            break;
            case 2:
                emodify(root, 1, m, l[x], i);
            break;
            case 3:
//                cout << x << " " << l[x] <<  " " << (int)(get(root, 1, m, l[x]) > eget(root, 1, m, l[x], r[x])) << " " << get(root, 1, m, l[x]) << " " << eget(root, 1, m, l[x], r[x]) << "\n";
                cout << (int)(get(root, 1, m, l[x]) > eget(root, 1, m, l[x], r[x])) << "\n";
            break;
        }
    }
    //cout << sizeof(color) + sizeof(empty) + sizeof(l) + sizeof(r) + sizeof(next) + sizeof(last) + sizeof(dest) << endl;
	return 0;
}
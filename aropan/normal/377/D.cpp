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

const int MAXT = 100007 * 8;
const int MAXX = 3 * 100007;

int n;
vector <int> e;
vector <int> l, v, r;

pair <int, int> mx[MAXT];
int dt[MAXT], lt[MAXT], rt[MAXT];
int root, k;

int getk(const int &i)
{
    return i > 0? 2 * l[i - 1] : 2 * v[-i - 1] + 1;
}

bool opr_sort(const int &i, const int &j)
{
    return getk(i) < getk(j);
}


void push(int &curr, const int l, const int r, const int D)
{
    if (l > r) {
        return;
    }
    if (curr == 0) {
        curr = ++k;
        mx[curr] = make_pair(0, l);
        dt[curr] = lt[curr] = rt[curr] = 0;
    }
    dt[curr] += D;
    mx[curr].first += D;
}

void push(int &curr, const int l, const int r)
{
    if (dt[curr]) {
        int c = (l + r) / 2;
        push(lt[curr], l, c, dt[curr]);
        push(rt[curr], c + 1, r, dt[curr]);
        dt[curr] = 0;
        mx[curr] = make_pair(0, l);
    }
}

void modify(int &curr, const int l, const int r, const int L, const int R, const int D)
{
    if (curr == 0) {
        curr = ++k;
        mx[curr] = make_pair(0, l);
        dt[curr] = lt[curr] = rt[curr] = 0;
    }
    
    if (L <= l && r <= R) {
        dt[curr] += D;
        mx[curr].first += D;
        return;
    }
    
    push(curr, l, r);
    
    int c = (l + r) / 2;
    if (L <= c) modify(lt[curr], l, c, L, R, D);
    if (c < R) modify(rt[curr], c + 1, r, L, R, D);
    
    mx[curr] = max(
        lt[curr]? mx[lt[curr]] : make_pair(0, l),
        rt[curr]? mx[rt[curr]] : make_pair(0, c + 1)
    );
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    while (cin >> n) {
        l.resize(n);
        v.resize(n);
        r.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> v[i] >> r[i];
        }
        e.clear();
        for (int i = 1; i <= n; ++i) {
            e.push_back(i);
            e.push_back(-i);
        }
        sort(e.begin(), e.end(), opr_sort);
        
        root = k = 0;
        int ans = 0;
        int lft, rgt;
        lft = rgt = -1;
        for (size_t i = 0; i < e.size(); ++i) {
            int ind = abs(e[i]) - 1;
            if (e[i] > 0) {
                modify(root, 1, MAXX, v[ind], r[ind], 1);
                if (mx[root].first > ans) {
                    ans = mx[root].first;
                    lft = l[ind];
                    rgt = mx[root].second;
//                    cout << ans << " " << lft << " " << rgt << endl; 
                }
                //cout << mx[root].first << endl;
            } else {
                modify(root, 1, MAXX, v[ind], r[ind], -1);
            }
        }
        
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            if (l[i] <= lft && rgt <= r[i] && lft <= v[i] && v[i] <= rgt) {
                cout << i + 1;
                ans -= 1;
                if (ans) {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }

	return 0;
}
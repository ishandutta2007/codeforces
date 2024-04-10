#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 4e5 + 10;
const lli mod = 1e9 + 7;
int n, m;
int b[N];
pair <int, int> a[N];
pair<pair <int, int>, int> q[N];
vector <int> pat;
int t[4*N], flag[4*N];
void push(int nd)
{
    t[nd]+=flag[nd];
    flag[nd*2]+=flag[nd];
    flag[nd*2+1]+=flag[nd];
    flag[nd] = 0;
}
void upd(int ql, int qr = n - 1, int nl = 0, int nr = n - 1, int nd = 1)
{
    push(nd);
    if(ql > nr || qr < nl) return;
    if(nl == ql && nr == qr)
    {
        flag[nd]++;
        push(nd);
        return;
    }
    int mid = (nl + nr)/2;
    upd(ql, min(mid, qr), nl, mid, nd * 2);
    upd(max(ql, mid + 1), qr, mid + 1, nr, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
int qry(int q, int nl = 0, int nr = n - 1, int nd = 1)
{
    push(nd);
    if(q < nl || q > nr) return 0;
    if(nl == nr)
    {
        return t[nd];
    }
    int mid = (nl + nr)/2;
    return qry(q, nl, mid, nd * 2) + qry(q, mid + 1, nr, nd * 2 + 1);
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fr;
        b[i] = a[i].fr;
        a[i].sc = -i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].fr.fr >> q[i].fr.sc;
        q[i].sc = i;
        pat.PB(0);
    }
    sort(q, q + m);
    int i1 = 0;
    for (int i = 0; i < n; i++)
    {
        upd(-a[i].sc);
        while(i1 < m && q[i1].fr.fr == i + 1)
        {
            int k = q[i1].fr.sc;
            int l = 0, r = n - 1, ans = 0;
            while(l <= r)
            {
                int m = (l + r)/2;
                if(qry(m) >= k)
                {
                    ans = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
            pat[q[i1].sc] = b[ans];
            i1++;
        }
    }
    for(auto p : pat)
    {
        cout << p << endl;
    }
    return 0;
}
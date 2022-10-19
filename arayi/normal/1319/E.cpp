#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
using namespace std;
lli gcd(lli a, lli b) {return (b==0LL ? a : gcd(b, a % b));}
ld dist(ld x1, ld y1, ld x2, ld y2)
{

    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

const int N = 4e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);

lli bp(lli a, lli b = mod - 2)
{

    lli ret = 1;
    while(b)
    {

        if(b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}

lli n, m, k, i1, ans = -3LL * mod;
pair <lli, lli> a[N], b[N];
pair <pair<lli, lli>, lli> c[N];
lli t[4 * N], flag[4 * N];
void push(int nd)
{
    flag[2 * nd] += flag[nd];
    flag[2 * nd + 1] += flag[nd];
    t[nd] += flag[nd];
    flag[nd] = 0;
}
void upd(int ql, int qr, lli val, int nl = 0, int nr = m - 1, int nd = 1)
{
    push(nd);
    if(ql > nr || qr < nl) return;
    if(ql == nl && qr == nr)
    {
        flag[nd] += val;
        push(nd);
        return;
    }
    int mid = (nl + nr) / 2;
    upd(ql, min(mid, qr), val, nl, mid, nd * 2);
    upd(max(mid + 1, ql), qr, val, mid + 1, nr , nd * 2 + 1);
    t[nd] = max(t[nd * 2], t[nd * 2 + 1]);
}
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
     cin >> a[i].fr >> a[i].sc;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i].fr >> b[i].sc;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> c[i].fr.fr >> c[i].fr.sc >> c[i].sc;
    }
    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + k);
    for(int i = 0; i < m; i++)
    {
        upd(i, i, -b[i].sc);
    }
    push(1);
    //cout << t[1] << endl;
    for(int i = 0; i < n; i++)
    {
        while(i1 < k && c[i1].fr.fr < a[i].fr)
        {
            if(c[i1].fr.sc + 1 <= b[m - 1].fr)
            {
                int ii = upper_bound(b, b + m, MP(c[i1].fr.sc + 1LL, 0LL)) - b;
                //cout << i1 <<  " " << ii << endl;
                upd(ii, m - 1, c[i1].sc);
            }
            i1++;
        }
        push(1);
        ans = max(ans, t[1] - a[i].sc);
    }
    cout << ans << endl;
    return 0;
}
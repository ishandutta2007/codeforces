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

const int N = 2e5 + 30;
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

int n, m, k, s, t;
int d[N], a[N];
vector <int> g[N], g1[N];
bool col[N];
int pat1, pat2;
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g1[b].PB(a);
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    s = a[0], t = a[k - 1];
    for(int i = 1; i <= n; i++)
    {
        d[i] = mod;
    }
    queue <int> q;
    d[t] = 0;
    col[t] = true;
    q.push(t);
    int p;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(auto p1 : g1[p])
        {
            if(!col[p1])
            {
                col[p1] = true;
                d[p1] = d[p] + 1;
                q.push(p1);
            }
        }
    }
    for(int i = 0; i < k - 1; i++)
    {
        if(d[a[i]] == d[a[i + 1]] + 1) continue;
        else pat1++;
    }
    for(int i = 0; i < k - 1; i++)
    {
        int sm = 0;
        if(d[a[i]] != d[a[i + 1]] + 1) pat2++;
        else
        {
            for(auto p : g[a[i]]) if(d[p] == d[a[i]] - 1) sm++;
            if(sm > 1) pat2++;
        }
    }
    cout << pat1 << " " << pat2 << endl;
    return 0;
}
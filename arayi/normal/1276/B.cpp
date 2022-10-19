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



const int N = 2e5 + 30;
const lli mod = 1e9 + 7;

int q;
bool col[N], col1[N];
vector <int> g[N];
int n, m, x, y;
lli sm1, sm2;
void dfs(int v)
{
    col[v] = true;
    if(v == x) return;
    for(auto p : g[v])
    {
        if(col[p]) continue;
        dfs(p);
    }
}
void dfs1(int v)
{
    col1[v] = true;
    if(v == y) return;
    for(auto p : g[v])
    {
        if(col1[p]) continue;
        dfs1(p);
    }
}
int main()
{
    fastio;
    cin >> q;
    while(q--)
    {
       cin >> n >> m >> x >> y;
      // cout << "SM" << endl;
       for (int i = 0; i < m; i++)
       {
           int a, b;
           cin >> a >> b;
           g[a].PB(b);
           g[b].PB(a);
       }
       dfs(y);
       dfs1(x);
       for (int i = 1; i <= n; i++)
       {
           //cout << col[i] << " " << col1[i] << endl;
           if(col[i] && !col1[i]) sm1++;
           else if(!col[i] && col1[i]) sm2++;
       }
       for (int i = 1; i <= n; i++)
       {
           g[i].clear();
           col[i] = false;
           col1[i] = false;
       }
       cout << sm1*sm2<<endl;
       sm1 = 0;
       sm2 = 0;
    }
    return 0;
}
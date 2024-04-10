#include <bits/stdc++.h>
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



const int N = 4e5 + 30;
const lli mod = -1e11;

int n, q;
int p[N], l[N], sum[N], xr[N], nerq[N], ln[N];
int a[N][30], dp[N][30];
int qan;
bool col[N], cl[N], bl;

vector <int> g[N];
void dfs(int v, int par)
{
    if(l[par] == 1)
    {
        for (int i = 0; i < 27; i++)
        {
            a[v][i] += a[par][i];
        }
        p[v] = p[par];
    }
    for(auto p1 : g[v])
    {
        dfs(p1, v);
    }
}
void upd(int v, int A, int B)
{
    if(v == 1)
    {
        return;
    }
    int par = p[v];
    //cout << v << " " << par << endl;
    if(A != 26)
        sum[par] -= dp[par][A];
    if(B != 26)
        sum[par] -= dp[par][B];
    dp[par][A] = dp[par][B] = 0;
    for(auto p : g[par])
    {
        p = nerq[p];
        //if(par == 1) cout << p << "<-";
        dp[par][A] = max(dp[par][A], dp[p][A] + a[p][A]);
        dp[par][B] = max(dp[par][B], dp[p][B] + a[p][B]);
    }
    if(A != 26)
        sum[par] += dp[par][A];
    if(B != 26)
        sum[par] += dp[par][B];
    if(sum[par] > xr[par] && !col[par]) qan++, col[par] = true;
    else if(sum[par] <= xr[par] && col[par]) qan--, col[par] = false;
    upd(par, A, B);
}
int main()
{
    fastio;
    cin >> n >> q;
    p[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        char A;
        cin >> A;
        if(A == '?') A = 26;
        else A -= 'a';
        a[i][A]++;
        ln[i] = A;
        l[p[i]]++;
        g[p[i]].PB(i);
    }
    for(int i = n; i >= 2; i--)
    {
        if(xr[p[i]] && xr[p[i]] != xr[i] + 1) bl = true;
        xr[p[i]] = xr[i] + 1;
        for (int j = 0; j < 27; j++)
        {
            dp[p[i]][j] = max(dp[p[i]][j], dp[i][j] + a[i][j]);
            sum[i] += dp[i][j];
        }
        sum[i] -= dp[i][26];
    }
    if(bl)
    {
        for (int i = 0; i < q; i++)
        {
            cout << "Fou\n";
        }
        return 0;
    }
    for (int i = 0; i < 26; i++)
    {
        sum[1] += dp[1][i];
    }
    for (int i = 1; i <= n; i++)
    {
        if(l[i] != 1) cl[i] = true;
        col[i] = xr[i] < sum[i];
        qan += col[i];
    }
    cl[1] = true;
    for(int i = n; i >= 1; i--)
    {
        if(!cl[i])
            nerq[i] = nerq[g[i][0]];
        else
            nerq[i] = i;
        //cout << nerq[i] << " ";
    }
    dfs(1, 1);
    for (int i = 0; i < q; i++)
    {
        int v;
        char A;
        cin >> v >> A;
        int sm1, sm2;
        if(A == '?') sm1 = 26;
        else sm1 = A - 'a';
        sm2 = ln[v];
        ln[v] = sm1;
        v = nerq[v];
        a[v][sm1]++;
        a[v][sm2]--;
        upd(v, sm1, sm2);
        //cout << dp[5]['w' - 'a'] << "|" << a[5]['w' - 'a'] << endl;
        if(qan)
        {
            cout << "Fou\n";
        }
        else
        {
            int sm = 0;
            //cout << sum[1] << endl;
            for (int i = 0; i < 26; i++)
            {
               // if(dp[1][i]) cout << char('a' + i) << "-" << dp[1][i] << "\n";
                sm += (i + 1) * (dp[1][i] + xr[1] - sum[1]);
            }
           // cout << "?-" << dp[1][26] << endl;
            cout <<  "Shi " << sm << endl;
        }
    }
    return 0;
}
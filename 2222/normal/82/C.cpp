#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
//#define tt (ll+rr)/2
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())

vector<bool> used;
vector<priority_queue<pii, vector<pii>, greater<pii> > > st;  

vector<vector<int> > G;

int c[5555][5555];

int pred[5555];

void dfs(int u, int pred)
{
        used[u] = true;

        if (u != 0)
        {
                int fl = c[u][pred];
                rept(iter, fl)
                {
                        if (st[u].size() == 0) break;
                        st[pred].push(st[u].top());
                        st[u].pop();
                }
        }

        rept(i, L(G[u]))
                if (!used[G[u][i]])
                        dfs(G[u][i], u); 
}

VI res;
int iter = 0, tot = 0;
void formAns()
{
        while (st[0].size() > 0)
        {
                tot++;
                res[st[0].top().second] = iter;
                st[0].pop();
        }
        iter++;
}

int main()
{
        #ifndef ONLINE_JUDGE 
        freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
        #endif

        int n;
        scanf("%d", &n);
        VI a(n);
        rept(i, n)
                scanf("%d", &a[i]);
        
        G.resize(n);

        //C(c);

        rept(i, n - 1)
        {
                int u, v, cc;
                scanf("%d%d%d", &u, &v, &cc);
                u--; v--;
                G[u].pb(v);
                G[v].pb(u);
                c[u][v] = c[v][u] = cc;
        }

        st.resize(n);

        rept(i, n)
                st[i].push(mp(a[i], i));

        res.assign(n, 0);

        while (tot < n)
        {
                formAns();
                used.assign(n, false);
                dfs(0, -1);
        }

        rept(i, L(res))
        {
                if (i) printf(" ");
                printf("%d", res[i]);
        }

        puts("");


        
        return 0;
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

vector<vector<pair<int, int>>> G;

const int N = 200000;

vector<vector<bitset<N>>> dp;
vector<vector<bool>> can;

ll res = 0;

int n, m, k;

vector<vector<vector<vector<bool>>>> check;

void recurse(vector<int> tmp)
{
    /*cout<<"recursing:"<<endl;
    for (auto it: tmp) cout<<it<<' ';
    cout<<endl;*/
    int cur = tmp.size();
    if (cur==k)
    {
        res++; return;
    }
    for (int cntcur = 0; cntcur<=cur; cntcur++) if (can[cur][cntcur])
    {
        bool ok = true;
        for (int i = 0; i<cur; i++) if (!check[i][cur][tmp[i]][cntcur])
        {
            ok = false; break;
        }
        if (ok)
        {
            vector<int> tmp1(tmp); tmp1.push_back(cntcur);
            recurse(tmp1);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    G.resize(n);
    for (int i = 0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        G[u].push_back(mp(w, v));
    }

    for (int i = 0; i<n; i++) sort(G[i].begin(), G[i].end());

    for (int i = 0; i<k; i++)
    {
        dp.push_back(vector<bitset<N>>(i+1));
        can.push_back(vector<bool>(i+1, true));
    }

    for (int i = 0; i<n; i++)
    {
        int deg = G[i].size();
        for (int j = 0; j<deg; j++)
        {
            if (dp[deg-1][j][G[i][j].second] == 1) can[deg-1][j] = false;
            else dp[deg-1][j][G[i][j].second] = 1;
        }
    }

    check = vector<vector<vector<vector<bool>>>>(k, vector<vector<vector<bool>>>(k, vector<vector<bool>>(k, vector<bool>(k))));

    for (int i = 0; i<k; i++)
        for (int j = i+1; j<k; j++)
        {
            for (int cnti = 0; cnti<=i; cnti++) if (can[i][cnti])
                for (int cntj = 0; cntj<=j; cntj++) if (can[j][cntj])
                {
                    if ((dp[i][cnti]&dp[j][cntj]).count() == 0) check[i][j][cnti][cntj] = true;
                }
        }

    /*for (int i = 0; i<k; i++)
    {
        cout<<i<<":"<<endl;
        for (auto it: dp[i]) cout<<it<<endl;
    }*/

    recurse({});
    cout<<res<<endl;

    //cout<<check[0][1][0][1]<<endl;


}
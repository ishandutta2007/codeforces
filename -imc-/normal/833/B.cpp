#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct node
{
    int left, right;
    short sum;
    
    node(int sum = 0): left(0), right(0), sum(sum) {}
    node(int left, int right);
};

const int MAX_NODES = 35000 * 100;
node nodes[MAX_NODES];
int nodePtr = 0;

node::node(int left, int right): left(left), right(right), sum(nodes[left].sum + nodes[right].sum) {}
    
int query(int t, int l, int r, int x, int y)
{
    if (x > r || y < l) return 0;
    
    if (l >= x && r <= y)
        return nodes[t].sum;
    
    int m = (l + r) / 2;
    return query(nodes[t].left, l, m, x, y) + query(nodes[t].right, m + 1, r, x, y);
}

int build(int l, int r)
{
    if (l == r)
        return nodePtr++;
    
    int m = (l + r) / 2;
    int x = nodePtr++;
    node nn(build(l, m), build(m + 1, r));
    nodes[x] = nn;
    return x;
}

int change(int t, int l, int r, int index, int value)
{
    int x = nodePtr++;
    if (l == r)
    {
        nodes[x] = node(value);
        return x;
    }
    
    int m = (l + r) / 2;
    
    if (index <= m)
        nodes[x] = node(change(nodes[t].left, l, m, index, value), nodes[t].right);
    else
        nodes[x] = node(nodes[t].left, change(nodes[t].right, m + 1, r, index, value));
    
    return x;
}

using li = long long;

int n;
vector<int> versions;

int cost(int i, int j)
{
#if 0
    int answer = 0;
    set<int> s;
    for (int k = i; k <= j; k++)
        if (!s.count(a[k]))
        {
            s.insert(a[k]);
            answer++;
        }
#endif
        
    assert(i <= j);
    int answerf = query(versions[j], 0, n - 1, i, j);
    //assert(answer == answerf);
    //printf("answer %d answerf %d\n", answer, answerf);
        
    return answerf;
}

vector<vector<int>> dpf, optf;
vector<int> a;

int have[35500];
int have_timer = 0;

void point_compute(int blocks, int i, int opt_l, int opt_r)
{
    dpf[blocks][i] = -1;
    optf[blocks][i] = -1;
    
    assert(min(i, opt_r + 1) >= opt_l);
    
    // omg you dibil
    int until = min(i, opt_r + 1);
    if (opt_r + 1 < i)
    {
        for (int j = until - 1; j >= opt_l; j--)
        {
            int can = dpf[blocks - 1][j] + cost(j, i - 1);
            if (can > dpf[blocks][i])
            {
                dpf[blocks][i] = can;
                optf[blocks][i] = j;
            }
        }
    }
    else
    {
        have_timer++;
        int cost = 0;
        
        for (int j = i - 1; j >= opt_l; j--)
        {
            //if (was.insert(a[j]).second)
            //    cost++;
            
            if (have[a[j]] != have_timer)
            {
                have[a[j]] = have_timer;
                cost++;
            }
            
            int can = dpf[blocks - 1][j] + cost;
            if (can > dpf[blocks][i])
            {
                dpf[blocks][i] = can;
                optf[blocks][i] = j;
            }
        }
    }
}

void compute(int blocks, int l, int r, int opt_l, int opt_r)
{
    if (l > r) return;
    
    if (l == r)
    {
        point_compute(blocks, l, opt_l, opt_r);
        return;
    }
    
    int m = (l + r) / 2;
    point_compute(blocks, m, opt_l, opt_r);
    
    compute(blocks, l, m - 1, opt_l, optf[blocks][m]);
    compute(blocks, m + 1, r, optf[blocks][m], opt_r);
    
    //printf("ok\n");
}

void solve(bool read)
{
    int k;
    if (read)
        cin >> n >> k;
    else
        n = 35000, k = rand() % min(n, 50) + 1;
    
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (read)
            cin >> a[i];
        else
            a[i] = rand() % n + 1;
    }
    
    int tree = build(0, n - 1);
    versions.assign(n, 0);
    
    map<int, int> lastPos;
    for (int r = 0; r < n; r++)
    {
        if (lastPos.count(a[r]))
        {
            tree = change(tree, 0, n - 1, lastPos[a[r]], 0);
        }
        tree = change(tree, 0, n - 1, r, 1);
        lastPos[a[r]] = r;
        
        versions[r] = tree;
    }
    
    //printf("built %f\n", clock() / (double)CLOCKS_PER_SEC);
    
#if 0
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1)), opt(k + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    
    for (int blocks = 1; blocks <= k; blocks++)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int can = dp[blocks - 1][j] + cost(a, j, i - 1);
                if (can > dp[blocks][i])
                {
                    dp[blocks][i] = can;
                    opt[blocks][i] = j;
                }
            }
            
            assert(opt[blocks][i] >= opt[blocks][i - 1]);
        }
            
    cout << dp[k][n] << endl;
#endif
    
    dpf.assign(k + 1, vector<int>(n + 1, -1));
    optf.assign(k + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= n; i++)
        dpf[0][i] = 0;
    
    for (int blocks = 1; blocks <= k; blocks++)
    {
        compute(blocks, 1, n, 0, n - 1);
#if 0
        bool fail = false, fail_opt = false;
        for (int i = 1; i <= n; i++)
        {
            printf("%d %d: dp: %d, dpf: %d, opt: %d, optf: %d\n", blocks, i, dp[blocks][i], dpf[blocks][i], opt[blocks][i], optf[blocks][i]);
            if (dp[blocks][i] != dpf[blocks][i])
                fail = true;
            if (opt[blocks][i] != optf[blocks][i])
                fail_opt = true;
        }
        assert(!fail);
        assert(!fail_opt);
#endif
    }
    
    cout << dpf[k][n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve(true);
    return 0;
    
    int nt = 1;
    //cin >> nt;
    
    //for (int i = 0; i < nt; i++)
    //    solve(true);
    
    solve(false);
    //printf("%d %d\n", nodePtr, MAX_NODES);
    
    //while (true)
    //    solve(false);
    
    return 0;
}
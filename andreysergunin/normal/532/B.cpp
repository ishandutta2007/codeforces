#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 300000;
const long long INF = 1e15;

vector<int> edge[MAXN];
int a[MAXN];

pair<long long, long long> dfs(int v)
{
    long long m = INF;
    long long s = 0;
    int k = 0;
    for (int i = 0; i < (int)edge[v].size(); i++)
    {
        pair<long long, long long> t = dfs(edge[v][i]);
        if (t.fs > t.sc)
            s += t.fs;
        else
        {
            s += t.sc;
            k++;
        }
        m = min(m, abs(t.sc - t.fs));
    }
    pair<long long, long long> ans;

    if ((int)edge[v].size() == 0)
        m = 0;

    if (k % 2 == 0)
        ans = make_pair(s, s + a[v]);
    else
        ans = make_pair(s - m, max(s - m + a[v], s));

//    cout << v << ' ' << ans.fs << ' ' << ans.sc << endl;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p >> a[i];
        if (i > 0)
            edge[p - 1].push_back(i);
    }
    pair<long long, long long> t;
    t = dfs(0);
    cout << max(t.fs, t.sc);
    return 0;
}
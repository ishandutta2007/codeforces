#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 4e5 + 7;
const int K = 20;

ll sum[N][K];
ll mx[N][K];
ll keep[N];
int depth[N];
int st_pr[N][K];
int st_jump[N][K];

void add(int v, int pr, int w)
{
    keep[v] = w;
    st_pr[v][0] = pr;
    for (int i = 1; i < K; i++)
    {
        st_pr[v][i] = st_pr[st_pr[v][i - 1]][i - 1];
    }
    mx[v][0] = w;
    for (int i = 1; i < K; i++)
    {
        mx[v][i] = max(mx[v][i - 1], mx[st_pr[v][i - 1]][i - 1]);
    }
    if (mx[pr][K - 1] >= w)
    {
        int cur = pr;
        for (int i = K - 1; i >= 0; i--)
        {
            if (mx[cur][i] < w)
            {
                cur = st_pr[cur][i];
            }
        }
        st_jump[v][0] = cur;
    }
    else
    {
        st_jump[v][0] = -1;
    }
    sum[v][0] = w;
    depth[v] = 1;
    if (st_jump[v][0] != -1)
    {
        depth[v] = depth[st_jump[v][0]] + 1;
    }
    for (int i = 1; i < K; i++)
    {
        if (st_jump[v][i - 1] != -1)
        {
            st_jump[v][i] = st_jump[st_jump[v][i - 1]][i - 1];
            sum[v][i] = sum[v][i - 1] + sum[st_jump[v][i - 1]][i - 1];
        }
        else
        {
            sum[v][i] = sum[v][i - 1];
            st_jump[v][i] = -1;
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < K; i++)
    {
        st_pr[1][i] = 1;
    }
    depth[1] = 1;
    int q;
    cin >> q;
    ll last = 0;
    int cnt = 1;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll p, q;
            cin >> p >> q;
            int r = p ^ last;
            int w = q ^ last;
            add(cnt + 1, r, w);
            cnt++;
        }
        else
        {
            ll p, q;
            cin >> p >> q;
            int v = p ^ last;
            ll x = q ^ last;
            if (sum[v][K - 1] <= x)
            {
                last = depth[v];
            }
            else
            {
                if (sum[v][0] <= x)
                {
                    int ans = 0;
                    for (int i = K - 1; i >= 0; i--)
                    {
                        if (sum[v][i] <= x)
                        {
                            ans += (1 << i);
                            x -= sum[v][i];
                            v = st_jump[v][i];
                        }
                    }
                    last = ans;
                }
                else
                {
                    last = 0;
                }
            }
            cout << last << '\n';
        }
    }
}
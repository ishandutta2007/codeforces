/*
    
    
    
    
    
    
    
    
    
    
    
    
                                      ever17
*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int sum = 0, nega = 1;
    char ch = getchar();
    while (ch > '9'||ch < '0')
    {
        if (ch == '-') nega = -1;
        ch = getchar();
    }
    while (ch <= '9'&&ch >= '0')sum=sum*10+ch-'0',ch=getchar();
    return sum * nega;
}
const int N = 1e6 + 9;
int n, m, h[N], dp_st[N], dp_ed[N], b[N], ans[N], vis[N];
vector<int> G[N], st, tmp;
int c[N << 1], pep;
struct node
{
    int a, b, id;
    int lb, rb;
}p[N];
inline int lowbit(int x) {return x & (-x);}
inline void update(int x, int k)
{
    while(x <= n + m)
    {
        c[x] = max(c[x], k);
        x += lowbit(x);
    }
}
inline int query(int x)
{
    int res = 0;
    while(x)
    {
        res = max(res, c[x]);
        x -= lowbit(x);
    }
    return res;
}
inline bool cmp(node xxx, node yyy)
{
    return xxx.a < yyy.a;
}
signed main()
{
    n = read(), m = read();
    int mx = 0, pep = n;
    for (int i = 1; i <= n; i++) h[i] = read(), b[i] = h[i];
    for (int i = 1; i <= m; i++) p[i].a = read(), p[i].b = read(), p[i].id = i, b[++pep] = p[i].b;
    sort(p + 1, p + m + 1, cmp);
    sort(b + 1, b + pep + 1);
    pep = unique(b + 1, b + pep + 1) - b - 1;
    for (int i = 1; i <= n; i++) h[i] = lower_bound(b + 1, b + pep + 1, h[i]) - b;
    for (int i = 1; i <= m; i++) p[i].b = lower_bound(b + 1, b + pep + 1, p[i].b) - b;
//  for (int i = 1; i <= n; i++) cout << h[i] << " " << p[i].b << endl;
    int now = 1;
    while(now <= m && p[now].a == 1) now++;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        dp_st[i] = query(h[i] - 1) + 1;
        update(h[i], dp_st[i]);
        while(now <= m && p[now].a == i + 1)
            ans[p[now].id] += query(p[now].b - 1), now++;
        mx = max(mx, dp_st[i]);
        G[dp_st[i]].push_back(i);
    }
    //cout << mx << endl;
    if(G[mx].size() == 1) vis[G[mx][0]] = 1;
    for (int i = 0; i < G[mx].size(); i++) st.push_back(G[mx][i]);
    for (int i = mx - 1; i >= 1; i--)
    {
        int now = st.size() - 1, chec = 0;
        tmp.clear();
        for (int j = G[i].size() - 1; j >= 0; j--)
        {
            while(now >= 0 && G[i][j] < st[now])
            {
                chec = max(chec, h[st[now]]), now--;
            }          
            if(h[G[i][j]] < chec) tmp.push_back(G[i][j]);
        }
        if(tmp.size() == 1) vis[tmp[0]] = 1;
        st.clear();
        for (int j = tmp.size() - 1; j >= 0; j--) st.push_back(tmp[j]);
    }
    memset(c, 0, sizeof(c));
    now = m;
    while(now >= 1 && p[now].a == n) now--;
    for (int i = n; i >= 1; i--)
    {
        dp_ed[i] = query(pep - h[i]) + 1;
        update(pep - h[i] + 1, dp_ed[i]);
        while(now >= 1 && p[now].a == i - 1)
        {
        //	cout << p[now].id << " " << p[now].b << endl;
            ans[p[now].id] += query(pep - p[now].b), now--;
  		}
    }
    //for (int i = 1; i <= 2; i++) cout << ans[i] << endl;
    for(int i = 1; i <= m; i++)
    {
        ans[p[i].id]++;
        ans[p[i].id] = max(ans[p[i].id], mx - vis[p[i].a]);
    }
    for(int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    return 0;
}
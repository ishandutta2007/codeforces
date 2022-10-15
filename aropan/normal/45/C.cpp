#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>


#define X first.first
#define I first.second
#define L second.first
#define R second.second

using namespace std;

typedef pair < pair <int, int>, pair <int, int> > hpair;

const int MAXN = 222222;

int n, m;
char s[MAXN];
int a[MAXN];
int left[MAXN], right[MAXN];
bool f[MAXN];
priority_queue < hpair, vector <hpair>, greater <hpair> > h;
pair <int, int> ans[MAXN];

int remove(int x)
{
    left[right[x]] = left[x];
    right[left[x]] = right[x];
    f[x] = true;
    return 0;
}

int add(int l, int r)
{
    if (f[l] || f[r] || s[l] == s[r]) return 0;
    h.push(make_pair(make_pair(abs(a[l] - a[r]), l), make_pair(l, r)));
    return 0;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d\n", &n);
    scanf("%s\n", s + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
        
    for (int i = 1; i <= n; i++)
    {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    f[0] = true;
    f[n + 1] = true;
    
    for (int i = 1; i < n; i++)
        add(i, i + 1);
        
    while (h.size())
    {
        int
            x = h.top().L,
            y = h.top().R;
        h.pop();
        if (f[x] || f[y]) continue;
        
        ans[m].first = x;
        ans[m].second = y;
        m++;
        
        int
            l = left[x],
            r = right[y];
            
        remove(x);
        remove(y);
        
        add(l, r);
    }
    
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
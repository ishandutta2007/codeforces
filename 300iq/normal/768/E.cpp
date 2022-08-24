#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 61;

int sz = 0;
map <ll, int> gr[N];

void rec(int n, ll mask)
{
    sz++;
    if (gr[n].count(mask))
    {
        return;
    }
    set <int> s;
    for (int i = 1; i <= n; i++)
    {
        if (mask & (1 << i))
        {
            rec(n - i, mask ^ (1 << i));
            s.insert(gr[n - i][mask ^ (1 << i)]);
        }
    }
    int cur = 0;
    while (s.count(cur))
    {
        cur++;
    }
    gr[n][mask] = cur;
}

int kek[] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        ans ^= kek[x];
    }
    puts(ans == 0 ? "YES" : "NO");
}
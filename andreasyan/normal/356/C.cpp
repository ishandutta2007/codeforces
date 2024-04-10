#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(43112);
const int N = 400005;

int a[5];

int bfs()
{
    map<vector<int>, int> mp;
    mp[{a[0], a[1], a[2], a[3], a[4]}] = 0;
    queue<vector<int> > q;
    q.push({a[0], a[1], a[2], a[3], a[4]});
    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        if (v[2] == 0 && v[1] == 0)
            return mp[v];
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (i == 0 || j == 4)
                    continue;
                if (v[i] == 0)
                    continue;
                vector<int> h = v;
                h[i]--;
                h[j]--;
                h[i - 1]++;
                h[j + 1]++;
                if (mp.find(h) == mp.end())
                {
                    mp[h] = mp[v] + 1;
                    q.push(h);
                }
            }
        }
    }
    return -1;
}

bool z;
int solv()
{
    int ans = 0;
    ans += min(a[1], a[2]);
    if (a[1] <= a[2])
    {
        a[3] += a[1];
        a[2] -= a[1];
        a[1] = 0;
    }
    else
    {
        a[3] += a[2];
        a[1] -= a[2];
        a[2] = 0;
    }
    if (a[1] > 0)
    {
        ans += (a[1] / 3) * 2;
        a[3] += (a[1] / 3);
        a[1] = (a[1] % 3);
        if (a[3] >= a[1])
            ans += a[1];
        else
            ans += 2;
        z = true;
    }
    else
    {
        ans += (a[2] / 3) * 2;
        if ((a[2] % 3) == 2)
            ans += 2;
        else if ((a[2] % 3) == 1)
        {
            if (a[4])
                ++ans;
            else
                ans += 2;
        }
        z = true;
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    /*while (1)
    {
        int b[5];
        for (int i = 0; i < 5; ++i)
            b[i] = a[i] = (rnf() % 8);
        int tans = bfs();
        if (tans == -1)
            continue;
        z = false;
        if (tans != solv())
        {
            if (z)
            {
                printf("WA\n");
                memcpy(a, b, sizeof b);
                solv();
            }
        }
    }*/
    int n;
    scanf("%d", &n);
    int q = 0;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
        q += x;
    }
    if (q <= 2 || q == 5)
    {
        printf("-1\n");
        return 0;
    }
    //printf("%d\n", bfs());
    printf("%d\n", solv());
    return 0;
}
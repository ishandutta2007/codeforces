#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int mex(const vector<int>& v)
{
    set<int> s;
    for (int i = 0; i < v.size(); ++i)
        s.insert(v[i]);
    for (int i = 0; ; ++i)
    {
        if (s.find(i) == s.end())
            return i;
    }
}

int k;

int gg(int x)
{
    if (k % 2 == 0)
    {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (x == 2)
            return 2;
        return ((x % 2) ^ 1);
    }
    else
    {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (x == 2)
            return 0;
        if (x == 3)
            return 1;
        if (x == 4)
            return 2;
        if (x % 2 == 1)
            return 0;
        return mex({gg(x / 2), gg(x - 1)});
    }
}

int g[N];
int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    int n;
    scanf("%d", &n);
    scanf("%d", &k);
    int ans = 0;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        ans ^= gg(x);
    }
    if (ans)
        printf("Kevin\n");
    else
        printf("Nicky\n");
    return 0;
    printf("%d ", g[0]);
    for (int i = 1; i < N; ++i)
    {
        if (i % 2 == 1)
            g[i] = mex({g[i - 1]});
        else
        {
            if (k % 2 == 0)
                g[i] = mex({g[i - 1], 0});
            else
                g[i] = mex({g[i - 1], g[i / 2]});
        }
        printf("%d ", g[i]);
        if (g[i] != gg(i))
            printf("WA\n");
    }
    printf("\n");
    return 0;
}
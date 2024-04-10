#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 100005;
const int MAXM = 200005;

int n, m, k;
int last[MAXN];
int next[MAXM], dest[MAXM];
int cnt[MAXN];
int f[MAXN];
int ans[MAXN];
queue <int> q;
vector <int> a, b;

void run()
{
    if (a.size() % 3 == 0) return;
/*
            printf("a:");
            for (int j = 0; j < (int)a.size(); j++)
                printf(" %d", a[j]);
            printf("\n");
            printf("b:");
            for (int j = 0; j < (int)b.size(); j++)
                printf(" %d", b[j]);
            printf("\n");
            fflush(stdout);
//*/
    for (int i = 0; i < (int)a.size(); i++)
        if (cnt[a[i]] + 2 <= (int)b.size())
        {
            for (int j = last[a[i]]; j; j = next[j])
                f[dest[j]] = k + 3;

            for (int j = 0, c = 0; c < 2; j++)
                if (f[b[j]] != k + 3)
                    swap(b[c++], b[j]);
            swap(a[i], a[0]);

            for (int j = last[a[0]]; j; j = next[j]) cnt[dest[j]]--;
            for (int j = last[b[0]]; j; j = next[j]) cnt[dest[j]]--;
            for (int j = last[b[1]]; j; j = next[j]) cnt[dest[j]]--;

            ++k;
            ans[a[0]] = k;
            ans[b[0]] = k;
            ans[b[1]] = k;

            a.erase(a.begin());
            b.erase(b.begin());
            b.erase(b.begin());

            break;
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        dest[i] = y;
        next[i] = last[x];
        last[x] = i;

        dest[i + m] = x;
        next[i + m] = last[y];
        last[y] = i + m;

        cnt[x]++;
        cnt[y]++;
    }

    for (int i = 1; i <= n; i++)
        f[i] = 2;

    for (int i = 1; i <= n; i++)
        if (f[i] == 2)
        {
            f[i] = 1;
            q.push(i);
            while (q.size())
            {
                int x = q.front();
                q.pop();

                for (int j = last[x]; j; j = next[j])
                    if (f[dest[j]] == 2)
                    {
                        f[dest[j]] = f[x] ^ 1;
                        q.push(dest[j]);
                    }
            }
        }
    for (int i = 1; i <= n; i++)
        (f[i]? a : b).push_back(i);
    if (a.size() % 3 == 2) swap(a, b);

//    printf("%d %d\n", a.size(), b.size());

    k = 0;
    run();
    swap(a, b);
    run();
    run();

    if (a.size() % 3 == 0 && b.size() % 3 == 0)
    {
        for (int i = 0; i < (int)a.size(); i += 3)
            ans[a[i]] = ans[a[i + 1]] = ans[a[i + 2]] = ++k;
        for (int i = 0; i < (int)b.size(); i += 3)
            ans[b[i]] = ans[b[i + 1]] = ans[b[i + 2]] = ++k;
        puts("YES");
        for (int i = 1; i <= n; i++)
        {
            printf("%d", ans[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
    }
    else
    {
        puts("NO");
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
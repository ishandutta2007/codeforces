#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int l[N], r[N];

vector<pair<int, int> > v[N];

int ans[N];
int rans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        v[l[i]].push_back(m_p(r[i], i));
    }
    vector<pair<int, int> > possible;
    priority_queue<pair<int, int> > q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            q.push(m_p(-v[i][j].first, v[i][j].second));
        }
        if (q.size() == 1)
        {
            ans[i] = q.top().second;
            q.pop();
        }
        else
        {
            ans[i] = q.top().second;
            q.pop();
            possible.push_back(m_p(ans[i], q.top().second));
        }
    }
    for (int i = 1; i <= n; ++i)
        rans[ans[i]] = i;
    for (int i = 0; i < possible.size(); ++i)
    {
        int x = possible[i].first;
        int y = possible[i].second;
        swap(rans[x], rans[y]);
        if (l[x] <= rans[x] && rans[x] <= r[x] && l[y] <= rans[y] && rans[y] <= r[y])
        {
            printf("NO\n");
            for (int i = 1; i <= n; ++i)
                printf("%d ", rans[i]);
            printf("\n");
            swap(rans[x], rans[y]);
            for (int i = 1; i <= n; ++i)
                printf("%d ", rans[i]);
            printf("\n");
            return;
        }
        swap(rans[x], rans[y]);
    }
    //while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", rans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
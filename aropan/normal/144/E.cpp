#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100007;

int n, m;
int r[MAXN], c[MAXN], l[MAXN];
pair <int, int> a[MAXN];
vector <int> ans;
priority_queue < pair <int, int> > h;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &r[i], &c[i]);
        l[i] = n - c[i] + 1;
        a[i] = make_pair(l[i], i);
//        printf("%d %d\n", l[i], r[i]);
    }
    printf("\n");
    sort(a, a + m);

    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < m && a[j].first == i)
        {
            h.push(make_pair(-r[a[j].second], a[j].second));
            j++;
        }

//        printf("s: %d, t: %d %d\n", h.size(), h.top().second, h.top().first);

        if (h.size())
        {
//            printf("%d %d\n", i, h.top().second + 1);
            ans.push_back(h.top().second + 1);
            h.pop();
        }

        while (h.size() && -i == h.top().first) h.pop();
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
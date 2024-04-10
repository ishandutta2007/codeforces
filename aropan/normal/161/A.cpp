#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>


#define L first.first
#define R first.second
#define I second

using namespace std;

const int MAXN = 100007;

pair < pair <int, int>, int > a[MAXN];
pair <int, int> b[MAXN];
int n, m, x, y;
vector < pair <int, int> > answer;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        a[i] = make_pair(make_pair(v - x, v + y), i);
    }
    sort(a, a + n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(b, b + m);

    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && a[j].R < b[i].first) j++;

        if (j < n && a[j].L <= b[i].first && b[i].first <= a[j].R)
        {
            answer.push_back(make_pair(a[j].I, b[i].I));
            j++;
        }
    }
    printf("%d\n", answer.size());
    for (int i = 0; i < (int)answer.size(); i++)
        printf("%d %d\n", answer[i].first + 1, answer[i].second + 1);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
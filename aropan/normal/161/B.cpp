#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

#define C first.first
#define T first.second
#define I second

const int MAXN = 1007;

typedef pair < pair <int, int>, int > mpair;

mpair a[MAXN];
vector <int> ans[MAXN];
double answer;
int n, m, k;

bool opr_sort(const mpair &a, const mpair &b)
{
    return a.T < b.T || a.T == b.T && a.C > b.C || a.T == b.T && a.C == b.C && a.I < b.I;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &k);
    answer = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].C, &a[i].T);
        a[i].I = i + 1;
        answer += a[i].C;
    }

    sort(a, a + n, opr_sort);


    int res = a[k - 1].C;
    for (int i = k; i < n; i++)
        res = min(res, a[i].C);

    for (int i = 0; i < k; i++)
    {
        ans[i].push_back(a[i].I);
        if (a[i].T == 1)
            answer -= ((i + 1 == k)? res : a[i].C) * .5;
    }

    for (int i = k; i < n; i++)
        ans[k - 1].push_back(a[i].I);

    printf("%.1lf\n", answer);
    for (int i = 0; i < k; i++)
    {
        printf("%d", ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); j++)
            printf(" %d", ans[i][j]);
        printf("\n");
    }
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct str
{
    int x, i;
    bool operator <(const str &a) const
    {
        return x < a.x;
    }
};

string arr[100010];
char tmp[1000010];
vector<str> sor;
char res[2000010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, x, mx, p, i, j;
    scanf("%d", &n);
    mx = 0;
    for(i = 0; i<n; i++)
    {
        scanf("%s%d", tmp, &m);
        arr[i] = tmp;
        for(j = 0; j<m; j++)
        {
            scanf("%d", &x);
            sor.push_back({ x, i });
            mx = max(mx, (int)arr[i].size() + x);
        }
    }

    sort(sor.begin(), sor.end());

    for(i = 1; i<mx; i++)
        res[i] = 'a';

    p = 1;
    for(str &e: sor)
    {
        p = max(p, e.x);
        for(i = p - e.x; i<arr[e.i].size(); i++)
            res[p++] = arr[e.i][i];
    }

    printf("%s", res+1);
    return 0;
}
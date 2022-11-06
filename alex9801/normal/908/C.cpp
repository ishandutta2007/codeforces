#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;

int arr[1010];
double res[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, r, i, j;
    scanf("%d%d", &n, &r);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
    {
        res[i] = r;
        for(j = 0; j < i; j++)
        {
            if(-2 * r <= arr[i] - arr[j] && arr[i] - arr[j] <= 2 * r)
            {
                res[i] = max(res[i], res[j] + sqrt(4 * r*r - (arr[i] - arr[j])*(arr[i] - arr[j])));
            }
        }
        printf("%.10lf ", res[i]);
    }
    return 0;
}
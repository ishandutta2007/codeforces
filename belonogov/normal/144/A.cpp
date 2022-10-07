#include <iostream>
#include <cstdio>

using namespace std;
int a[1000];

int main()
{
  //  freopen("in", "r", stdin);
 //   freopen("out", "w", stdout);
    int n, i, Min = 10000, Max = -1, pmin, pmax, ans;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] > Max){
            Max = a[i];
            pmax = i;
        }
        if (a[i] <= Min){
            Min = a[i];
            pmin = i;
        }
    }
    ans = pmax + n - pmin - 1;
    if (pmax > pmin)
        ans--;
    printf("%d", ans);
    return 0;
}
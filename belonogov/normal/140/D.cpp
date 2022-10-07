#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[100000];

int main()
{
    int n, i, res, sum;
    bool check;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    i = 0;
    sum = 0;
    res = 0;
    check = true;
    while (check && i < n){
        if (sum + a[i] > 710){
            check = 0;
            continue;
        }
        sum += a[i];
        if (sum > 350)
            res += sum - 350;
        i++;
    }
    printf("%d %d", i, res);

    return 0;
}
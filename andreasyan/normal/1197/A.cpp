#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int minu = min(a[n], a[n - 1]);
    int q = n - 2;
    cout << min(minu - 1, q) << endl;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
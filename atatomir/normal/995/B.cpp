#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 211;

int n, i, j, v[maxN];
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n); n *= 2;
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);

    for (i = 1; i <= n; i += 2) {
        for (j = i + 1; v[j] != v[i]; j++);
        ans += j - i - 1;
        for (; j > i + 1; j--) swap(v[j], v[j - 1]);
    }

    printf("%d", ans);



    return 0;
}
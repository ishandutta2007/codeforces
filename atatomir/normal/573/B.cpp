#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n,i;
int h[maxN];
int dp_left[maxN], dp_right[maxN];
int ans = 1;

int main()
{
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&h[i]);

    for (i = 1; i <= n; i++) dp_left[i] = min(dp_left[i-1] + 1, h[i]);
    for (i = n; i >= 1; i--) dp_right[i] = min(dp_right[i+1] + 1, h[i]);

    for (i = 1; i <= n; i++) ans = max(ans, min(dp_left[i], dp_right[i]));
    printf("%d",ans);

    return 0;
}
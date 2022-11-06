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

#define maxN 300011

int n, i, pos;
int p[maxN];
bool us[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]), us[i] = true;
    us[0] = true; pos = n;

    printf("%d ", 1);
    for (i = 1; i <= n; i++) {
        us[p[i]] = false;
        while (!us[pos]) pos--;

        printf("%d ", 1 + pos - (n - i));
    }


    return 0;
}
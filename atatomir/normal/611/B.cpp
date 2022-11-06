#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long

int i, j;
ull a, b;
ull mask, aux;
int ans;

int main()
{
    //freopen("test.in","r",stdin);
    scanf("%I64d%I64d", &a, &b);

    mask = 0;
    for (i = 0; i < 64; i++) {
        mask |= 1LL << i;

        for (j = 0; j < i; j++) {
            aux = mask ^ (1LL << j);
            if (a <= aux && aux <= b)
                ans++;
        }
    }

    printf("%d", ans);


    return 0;
}
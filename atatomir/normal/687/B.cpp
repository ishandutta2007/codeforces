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

#define maxN 1000011

int n, k, i, j, aux;
int a, b;
vector<int> divs[maxN];
int pp[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    for (i = 2; i < maxN; i++) {
        if (divs[i].size() != 0) continue;

        for (j = i; j < maxN; j += i) divs[j].pb(i);
    }


    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);

        for (auto e : divs[a]) {
            aux = 0;
            b = a;

            while (b % e == 0) {
                aux++;
                b /= e;
            }

            pp[e] = max(pp[e], aux);
        }
    }

    for (auto e : divs[k]) {
        aux = 0;
        b = k;

        while (b % e == 0) {
            aux++;
            b /= e;
        }

        if (pp[e] < aux) {
            printf("No");
            return 0;
        }
    }

    printf("Yes");

    return 0;
}
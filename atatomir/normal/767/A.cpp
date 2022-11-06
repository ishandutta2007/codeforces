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

#define maxN 100011

int n, i;
int p[maxN];

int pos;
bool valid[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n); pos = n;
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        valid[p[i]] = true;

        while (pos > 0 && valid[pos]) {
            printf("%d ", pos);
            pos--;
        }
        printf("\n");
    }


    return 0;
}
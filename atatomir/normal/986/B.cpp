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

const int maxN = 1000011;

int n, i, cnt, go, v;
int p[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (i = 1; i <= n; i++) {
        if (p[i] == 0) continue;
        cnt++;

        for (int aux = i; p[aux] != 0; aux = go) {
            go = p[aux];
            p[aux] = 0;
        }
    }

    v = n - cnt;
    cerr << v << '\n';

    if ((v % 2) == ((3 * n) % 2)) 
        printf("Petr");
    else
        printf("Um_nik");

    return 0;
}
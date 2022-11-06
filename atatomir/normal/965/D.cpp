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

const int maxN = 100011;
const int inf = 1000000000;

int n, l, i, p;
int here[maxN], rem[maxN];

int nxt[maxN], aux;

int Find(int x) {
    if (nxt[x] == x) return x;
    nxt[x] = Find(nxt[x]);
    return nxt[x];
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> l;
    for (i = 1; i < n; i++) cin >> rem[i];
    rem[n] = inf;
    here[0] = inf;

    for (i = 1; i <= n; i++)  {
        if (rem[i] > 0)
            nxt[i] = i;
        else
            nxt[i] = i - 1;
    }

    for (i = 0; i < n; i++) {
        while (true) {
            p = Find(min(n, i + l));
            if (p <= i) break;
            if (here[i] == 0) break;

            aux = min(here[i], rem[p]);
            here[i] -= aux;
            rem[p] -= aux;
            here[p] += aux;

            if (rem[p] == 0) nxt[p] = p - 1;
        }
    }

    cout << here[n];

    return 0;
}
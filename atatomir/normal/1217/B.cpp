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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

int t, x, d, h, n;
int best_hit;
int best_decr;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        scanf("%d%d", &n, &x);
        best_hit = best_decr = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &d, &h);

            best_hit = max(best_hit, d);
            best_decr = max(best_decr, d - h);
        }

        x = max(0, x - best_hit);
        if (x == 0) {
            printf("1\n");
            continue;
        }

        if (best_decr == 0) {
            printf("-1\n");
            continue;
        }

        printf("%d\n", 1 + (x + best_decr - 1) / best_decr);
    }


    return 0;
}
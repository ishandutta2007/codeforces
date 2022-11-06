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
#define Point pair<ll, ll>

int n, i;
Point P[maxN];
int A, B, C;
ll aux;

ll dist(int id1, int id2) {
    return (P[id1].first - P[id2].first) * (P[id1].first - P[id2].first) +
           (P[id1].second - P[id2].second) * (P[id1].second - P[id2].second);
}

ll cross(int id1, int id2, int id3) {
    Point p1 = mp(P[id2].first - P[id1].first, P[id2].second - P[id1].second);
    Point p2 = mp(P[id3].first - P[id1].first, P[id3].second - P[id1].second);

    return p1.first * p2.second - p1.second * p2.first;
}

int main()
{
    //freopen("test.in","r",stdin);

    A = 1;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%I64d %I64d", &P[i].first, &P[i].second);

    aux = dist(1, 2);
    B = 2;

    for (i = 3; i <= n; i++) {
        ll now = dist(1, i);
        if (now < aux) {
            aux = now;
            B = i;
        }
    }

    aux = 9000000000000000001;

    for (i = 2; i <= n; i++) {
        ll good = cross(A, B, i);

        if (good == 0) continue;
        ll now = dist(1, i);
        if (now < aux) {
            aux = now;
            C = i;
        }
    }

    printf("%d %d %d", A, B, C);

    return 0;
}
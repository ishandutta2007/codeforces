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

struct ant {
    int id;
    ll pos;
    char dir;

    bool operator<(const ant& who)const {
        return pos < who.pos;
    }
};

ll n, m, t, i;
ant A[maxN];
ll shift;

ll act;
vector<ll> wh;
ll ans[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &m, &t);
    for (i = 0; i < n; i++) {
        A[i].id = i + 1;
        scanf("%lld %c\n", &A[i].pos, &A[i].dir);
        A[i].pos--;
    }

    sort(A, A + n);
    for (i = 0; i < n; i++) {
        act = A[i].pos + t * (A[i].dir == 'L' ? -1 : 1);
        wh.pb( ((act % m) + m) % m );

        if (act > 0)
            shift += act / m;
        else
            shift += (act - m + 1) / m;


    }

    sort(wh.begin(), wh.end());
    shift = (shift % n) + n;
    shift %= n;

    for (i = 0; i < n; i++)
        ans[A[i].id] = 1 + wh[ (i + shift) % n ];

    for (i = 1; i <= n; i++) printf("%lld ", ans[i]);


    return 0;
}
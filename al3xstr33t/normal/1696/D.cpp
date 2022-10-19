#include<bits/stdc++.h>

using namespace std;

const int maxN = 250009;
int N, rgt[maxN], a[maxN], small[maxN], big[maxN];

int getLastBefore(int maxPos, int stk[], int l) {
    /// returns max position in stack of decreasing positions that is smaller than maxPos
    assert (l > 0);
    assert (stk[l] < maxPos);
    int p = 1, u = l - 1, ras = l;
    while (p <= u) {
        int mid = (p + u) >> 1;
        if (stk[mid] < maxPos) ras = mid, u = mid - 1;
        else p = mid + 1;
    }
    return stk[ras];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]);
    int lBig = 0, lSmall = 0;
    big[0] = small[0] = N + 1;
    for (int i=N; i>=1; i--) {
        while (lBig > 0 && a[big[lBig]] < a[i])
            lBig --;
        while (lSmall > 0 && a[small[lSmall]] > a[i])
            lSmall --;
        if (i < N) {
            if (a[i] > a[i + 1])
                rgt[i] = getLastBefore(big[lBig], small, lSmall);
            else
                rgt[i] = getLastBefore(small[lSmall], big, lBig);
        }
        big[++lBig] = i;
        small[++lSmall] = i;
    }
    int ans = 0, i = 1;
    while (i < N)
        i = rgt[i], ans ++;
    printf("%d\n", ans);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/
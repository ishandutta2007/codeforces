#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 2100;

int A[N], B[N];
int n;

const int SZ = N * 10 * 10 * 10 * 10;
int mem[SZ];

int go(int x, int pos, vector<int> elev)
{
    int ADD1 = 0;
    int ADD2 = 0;
    
    forn(i, 4) if (elev[i] == pos) elev[i] = 0, ADD1++;

    if (x == n)
    {
        int ok = 1;
        forn(i, 4) if (elev[i]) ok = 0;
        if (ok) return ADD1;
    }
    
    int hash = x * 10 + pos;
    sort(elev.begin(), elev.end());
    reverse(elev.begin(), elev.end());
    assert(elev[3] == 0);

    forn(i, 3) hash = hash * 10 + elev[i];
    
    int &res = mem[hash];
    if (res != -1) return res + ADD1;

    res = 1e9;

    int hasFree = 0;
    forn(i, 4) if (elev[i] == 0 && x < n)
    {
        if (A[x] == pos)
        {
            elev[i] = B[x];
            x++;
            ADD2++;
        }
        else hasFree = 1;
    }

    if (hasFree) res = min(res, abs(A[x] - pos) + go(x, A[x], elev) + ADD2);

    forn(i, 4) if (elev[i] != 0)
    {
        res = min(res, abs(elev[i] - pos) + go(x, elev[i], elev) + ADD2);
    }
    return res + ADD1;
}



int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    memset(mem, -1, sizeof mem);
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", &A[i], &B[i]);
    vector<int> elev = {0, 0, 0, 0};
    int res = go(0, 1, elev);
    printf("%d\n", res);

    return 0;
}
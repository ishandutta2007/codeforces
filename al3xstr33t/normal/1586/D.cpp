#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 100;
int N, M, s[maxN], p[maxN], q[maxN], ans[maxN], prv[maxN], nxt[maxN];
const bool DBG = 0;

void init() {
    const bool fromFile = 0;
    if (!fromFile) {
        for (int i=1; i<=N; i++)
            p[i] = i;
        random_shuffle(p + 1, p + N + 1);
    }
    else {
        for (int i=1; i<=N; i++)
            scanf("%d", &p[i]);
    }
}

int query() {
    if (DBG) {
        int ans = 0;
        for (int i=1; i<=N; i++)
            s[i] = p[i] + q[i];
        for (int i=N; i>=1; i--) {
            bool ok = 0;
            for (int j=i + 1; j<=N; j++)
                ok |= s[i] == s[j];
            if (ok)
                return i;
        }
        return 0;
    }
    printf("?");
    for (int i=1; i<=N; i++)
        printf (" %d", q[i]);
    printf("\n"); fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

void finish() {
    if (DBG) {
        bool ok = 1;
        for (int i=1; i<=N; i++)
            ok &= ans[i] == p[i];
        if (ok) printf ("OK\n");
        else {
            printf("WA\n");
            for (int i=1; i<=N; i++)
                printf("%d ", p[i]);
            printf ("\n found:\n");
            for (int i=1; i<=N; i++)
                printf("%d ", ans[i]);
            printf("\n");
            exit(0);
        }
    }
    printf("!");
    for (int i=1; i<=N; i++)
        printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
}

void solve() {
    for (int i=1; i<=N; i++)
        prv[i] = -1, nxt[i] = -1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            q[j] = (i == j ? 2 : 1);
        int pos = query();
        if (pos != i && pos != 0) {
            assert(pos < i);
            prv[pos] = i;
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            q[j] = (i == j ? 1 : 2);
        int pos = query();
        if (pos != i && pos != 0) {
            assert(pos < i);
            prv[i] = pos;
        }
    }
    int pos = 1;
    while (prv[pos] != -1)
        pos ++;
    for (int i=1; i<=N; i++)
        if (prv[i] != -1)
            nxt[prv[i]] = i;
    int i = 1;
    while (i < N) {
        ans[pos] = i;
        pos = nxt[pos], i ++;
    }
    ans[pos] = N;
    finish();
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//srand(time(0));
scanf("%d", &N);
int tests = DBG ? 100 : 1;
while(tests --) {
    if (DBG)
        init();
    solve();
}
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/
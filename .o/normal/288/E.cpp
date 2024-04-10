#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = (ll)1e15;

const int N_ = 100005;
const ll MOD = 1000000007;

ll MD(ll a) { return (a + MOD * 10000ll) % MOD; }
int PLUS (ll a, ll b) { return (MD(a) + MD(b)) % MOD; }
int MUL  (ll a, ll b) { return (MD(a) * MD(b)) % MOD; }

char X[N_], Y[N_];
int N;

int A[N_] = {0, 11, }, B[N_] = {0, 11, };
int E[N_] = {0, 11, };
int P2[N_] = {1, 2, }, P10[N_] = {1, 10, };
int F[N_] = {0, 0}, T[N_] = {0, 28};

int paste_prefix (int l, int pf) {
    ll prefix = MUL(MD(pf), P10[l]);
    ll ret = 0;

    ret = PLUS( ret, MUL(MUL(prefix, prefix), PLUS(P2[l], -1) ) );
    ret = PLUS( ret, MUL(prefix, B[l]) );
    ret = PLUS( ret, T[l] );

    return ret;
}

ll get (char* V) {
    ll ret = 0, prefix = 0, last = 0;
    for(int i = 1; i <= N; i++) {
        if(V[i] == '7') {
            ll tmpf = PLUS( MUL(prefix, 10), 4 );
            ll first = PLUS( MUL(tmpf, P10[N - i]), MUL(4, E[N - i]) );
            ret = PLUS(ret, MUL(last, first) );
            ret = PLUS(ret, paste_prefix(N - i, tmpf));
            last = PLUS( MUL(tmpf, P10[N - i]), MUL(7, E[N - i]) );
        }
        prefix = PLUS( MUL(prefix, 10), (V[i] - '0') );
    }
    ret = PLUS(ret, MUL(last, prefix) );
    return ret;
}

int main() {
    int i, j, k;

    scanf("%s%s", X+1, Y+1);
    N = strlen(X+1);

    E[1] = 1;
    //printf("%3s - %12s%12s%12s%12s%12s%12s%12s\n", "", "E", "P2", "P10", "A", "B", "F", "T");

    for(i = 2; i <= N; i++) {
        E[i] = PLUS( MUL(E[i - 1], 10), 1 );
        P2[i] = MUL(P2[i - 1], 2);
        P10[i] = MUL(P10[i - 1], 10);
        A[i] = PLUS( MUL(A[i - 1], 20), MUL(P2[i - 1], 11) );
        B[i] = PLUS( MUL(A[i], 2), -MUL(11, E[i]) );
        F[i] = paste_prefix (i - 1, 4);

        T[i] = PLUS(F[i], paste_prefix (i - 1, 7));
        T[i] = PLUS(T[i],
                    MUL( PLUS( MUL(4, P10[i - 1]), MUL(7, E[i - 1]) ),
                          PLUS( MUL(7, P10[i - 1]), MUL(4, E[i - 1]) ) )
                    );

        //printf("%3d - %12d%12d%12d%12d%12d%12d%12d%12d L\n", i,E[i],P2[i],P10[i],A[i],B[i],F[i],T[i]);
    }

    printf("%d\n", PLUS(get(Y), -get(X)));
	return 0;
}
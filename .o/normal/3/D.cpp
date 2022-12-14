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

/*
if P[i]
*/

void WRONG() {
    puts("-1");
    exit(0);
}

const int N_ = 100005;

int N;
char P[N_], R[N_];

struct S {
    int k, v;
    S(): v(0), k(0) { }
    S(int k, int v): v(v), k(k) {}
    bool operator < (const S &t) const { return v > t.v; }
};

priority_queue <S> PQ;

int main (){
    int i, j, k;

    scanf("%s", P+1);
    N = strlen(P+1);

    int depth = 0;
    ll cost = 0;

    for(i = 1; i <= N; i++) {
        R[i] = P[i];
        if(P[i] == '(') {
           ++depth;
        }else if(P[i] == ')'){
            --depth;
        }else {
            int a, b;
            scanf("%d%d", &a, &b);
            R[i] = ')';
            --depth;
            PQ.push (S(i, a - b));
            cost += b;
        }

        if(depth < 0) {
            if(PQ.empty()) WRONG();
            S t = PQ.top(); PQ.pop();
            R[t.k] = '('; cost += t.v; depth += 2;
        }
    }

    if(depth > 0) WRONG();
    printf("%lld\n%s\n", cost, R+1);

    return 0;
}
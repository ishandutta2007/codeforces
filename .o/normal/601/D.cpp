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
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 300500;

int N;
int C[N_];
char S[N_];
vector<int> gph[N_];

int sizeofSubtree[N_];
int dif[N_];

const int ALPHABET_SIZE = 26;
const int NUM_NODES = N_ * 2;

int child[NUM_NODES][ALPHABET_SIZE];
int sizeofSubtrie[NUM_NODES];

void mergeTwoTries (int r1, int r2) {
    int &sz = sizeofSubtrie[r1];
    sz = 1;
    for(int c = 0; c < 26; c++) {
        int &ch1 = child[r1][c];
        int &ch2 = child[r2][c];
        if(ch2 > 0) {
            if(ch1 == 0) ch1 = ch2;
            else mergeTwoTries(ch1, ch2);
        }
        sz += sizeofSubtrie[ch1];
    }
}

void iterateTrie (int node, string cur) {
    printf("  node %d(%d): ", node, sizeofSubtrie[node]); puts(cur.c_str());
    for(char c = 'a'; c <= 'z'; c++) {
        int ch = child[node][c - 'a'];
        if(ch > 0) iterateTrie(ch, cur + c);
    }
}

void solve (int u, int p = -1) {
    sizeofSubtree[u] = 1;

    int target = -1;
    for(auto v : gph[u]) if(v != p) {
        solve(v, u);
        sizeofSubtree[u] += sizeofSubtree[v];
        if(target == -1 || sizeofSubtree[target] < sizeofSubtree[v]) target = v;
    }

    // : target     ,  target  .
    //  :    
    for(auto v : gph[u]) if(v != p && v != target) {
        mergeTwoTries(target, v);
    }

    if(target < 0) target = N + u, sizeofSubtrie[target] = 1;;

    child[u][S[u] - 'a'] = target;
    sizeofSubtrie[u] = 1 + sizeofSubtrie[target];
    dif[u] = sizeofSubtrie[target];
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", C+i);
    scanf("%s", S+1);
    for(int i = 1; i <= N-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        gph[u].push_back(v);
        gph[v].push_back(u);
    }

    solve(1);

    int minElement = dif[1] + C[1], minCount = 1;
    for(int i = 2; i <= N; i++) {
        int currentValue = dif[i] + C[i];
        if(minElement < currentValue) {
            minElement = currentValue;
            minCount = 1;
        }else if(minElement == currentValue) {
            minCount += 1;
        }
    }

    printf("%d\n%d\n", minElement, minCount);
    return 0;
}
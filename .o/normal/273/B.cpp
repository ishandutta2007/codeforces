#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <assert.h>
 
typedef long long lld;
using namespace std;
typedef vector<int> vi;
typedef vi::iterator vii;
typedef set<int> si;
typedef si::iterator sii;
const int INF = 987654321;
const int N_ = 200005;

struct P{
    int x, y;
    P(): x(0), y(0){ }
    P(int x, int y): x(x), y(y){ }
    bool operator< (const P &t) const{
        return x != t.x ? x < t.x : y < t.y;
    }
};

int N;
lld MOD;
vector<P> D;
lld res = 1;
int X, S;
int CX[N_];

int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        int y; scanf("%d", &y);
        D.push_back( P(y, i) );
    }
    for(i = 1; i <= N; i++) {
        int y; scanf("%d", &y);
        D.push_back( P(y, i) );
    }
    scanf("%lld", &MOD);
    
    /*fac[0] = pow2[0] = 1 % MOD;
    for(i = 1; i <= N * 2; i++){
        if(i % 2 == 0) fac[i] = (fac[i - 1] * i / 2) % MOD;
        else fac[i] = (fac[i - 1] * i) % MOD;
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }*/
    
    sort(D.begin(), D.end());
    for(i = 0; i < D.size(); i++){
        if(i > 0 && D[i].x != D[i - 1].x) ++X;
        if(i > 0 && D[i].x == D[i - 1].x && D[i].y == D[i - 1].y) ++S;
        ++CX[X];
    }
    
    for(i = 0; i <= X; i++){
        for(j = 1; j <= CX[i]; j++){
            int x = j;
            while(S > 0 && !(x & 1)) x >>= 1, --S;
            res = (res * x) % MOD;
        }
    }
    printf("%lld\n", res % MOD);
    return 0;
}
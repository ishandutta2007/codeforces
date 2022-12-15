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
const ll LINF = 1e15;

const int N_ = 500005;

int N, D[N_];

vector<int> Gph[N_];
ll Table[N_];
int Que[N_], Qf, Qr;
bool Chk[N_];

int main() {
    int i, j, k;

    scanf("%d", &N);
    for(i = 2; i <= N; i++) {
        scanf("%d", &D[i]); 
        k = i - D[i];
        if(k > 0 && k <= N) Gph[k].push_back(i + N);
        k = i + D[i];
        if(k > 0 && k <= N) Gph[k + N].push_back(i);
    }

    for(i = 2; i <= N; i++) {
        if(i - D[i] <= 0) {
            Table[i + N] = D[i];
            Chk[i + N] = 1;
            Que[++Qr] = i + N;
        } 

        if(i + D[i] > N) {
            Table[i] = D[i];
            Chk[i] = 1;
            Que[++Qr] = i;
        }
    }

    while(Qf < Qr) { 
        int f = Que[++Qf];
        for(i = 0; i < Gph[f].size(); i++) {
            int g = Gph[f][i];
            if(!Chk[g]) {
                int t = g; if(t > N) t -= N;
                Table[g] = Table[f] + D[t];
                Chk[g] = 1; Que[++Qr] = g;
            }
        }
    }

    for(i = 1; i < N; i++){
        if(!Chk[i + N + 1]) puts("-1");
        else printf("%I64d\n", i + Table[i + N + 1]);
    }

    return 0;
}
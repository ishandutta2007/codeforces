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

using namespace std;
typedef long long ll;
typedef long double llf;
typedef unsigned long long llu;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 1005;

int N, M;
int ATK[N_], DEF[N_], STR[N_], AN, DN, SN;
char tmp[N_];
int res;

int main() {
    int i, j, k;

    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++) {
    	int t; scanf("%s%d", tmp, &t);
    	if(*tmp == 'A') ATK[++AN] = t;
    	else DEF[++DN] = t;
    }
    for(i = 1; i <= M; i++) scanf("%d", STR+i);

    sort(ATK+1, ATK+AN+1);
    sort(DEF+1, DEF+DN+1);
    sort(STR+1, STR+M+1);

    for(i = 1; i <= M && i <= AN; i++) {
    	int sum = 0;
    	for(j = 1; j <= i; j++) sum += max(0, STR[M - i + j] - ATK[j]);
    	if(j > i && res < sum) res = sum;
    }

    for(i = 1, j = 0; i <= DN; i++) {
    	while(++j <= M) {
    		if(DEF[i] < STR[j]) {
    			STR[j] = 0;
    			break;
    		}
    	}
    	if(j > M) break;
    }

    if(i == DN + 1 && N < M) {
    	sort(STR+1, STR+M+1);
    	bool chk = false;
    	for(j = 1; j <= AN && !chk; j++) {
    		if(ATK[j] > STR[M - AN + j]) chk = true;
    	}
    	if(!chk) {
    		int sum = 0;
    		for(k = 1; k <= M ; k++) sum += STR[k];
    		for(k = 1; k <= AN; k++) sum -= ATK[k];
    		if(res < sum) res = sum;
    	}
    }

    printf("%d\n", res);
    return 0;
}
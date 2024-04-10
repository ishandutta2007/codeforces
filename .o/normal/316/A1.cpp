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

inline int getint() {
	int n; scanf("%d", &n);
	return n;
}

inline ll getll() {
	ll n; scanf("%I64d", &n);
	return n;
}

char D[100005];
bool C[100];
int qc, qf, ac, af, qr = 1, ar = 1;

int main() {
	int i, j, k;

	scanf("%s", D);

	for(char *p = D; *p; *p++) {
		if(p == D) {
			if(*p == '?') qf = 1;
			if('A' <= *p && *p <= 'J') af = 1;
		}
		if(*p == '?') ++qc;
		if('A' <= *p && *p <= 'J' && !C[*p-'A']) ++ac, C[*p-'A']=1;
	}

	for(i = 1; i <= qc - qf; i++) qr *= 10;
	for(i = 1; i <= qf; i++) qr *= 9;

	if(af) {
		for(i = 2; i <= 9; i++) ar *= i;
		ar *= 9;
	}else {
		for(i = 2; i <= 10; i++) ar *= i;
	}

	for(i = 2; i <= 10 - ac; i++) ar /= i;

	if(qr == 0) qr = 1;
	if(ar == 0) ar = 1;
	printf("%d\n", ar * qr);

	return 0;
}
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

const int N_ = 1000005;

char S[N_];

int main() {
	int i, j, k;

	gets(S);
	for(char *p = S; *p != 0; p++) {
		if(*p == '\"') {
			printf("<");
			while(*(++p) != '\"' && *p != 0) putchar(*p);
			printf(">\n");
		}else if(*p != ' '){
			printf("<");
			while(*p != ' ' && *p != 0) putchar(*(p++));
			printf(">\n");
		}
	}
	return 0;
}
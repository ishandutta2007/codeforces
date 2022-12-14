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

const int N_ = 205;
int N;
int tb[N_][N_][N_];
char S[N_];
int cnt[3];

int main() {
	scanf("%d%s", &N, S);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 3; j++)
			if(S[i] == "BGR"[j]) cnt[j]++;
	}

	tb[1][0][0] = 1;
	tb[0][1][0] = 2;
	tb[0][0][1] = 4;
	for(int sum = 0; sum <= 200; sum++) {
		for(int i = 0; i <= 200; i++) for(int j = 0; j <= 200; j++) {
			int k = sum - (i + j);
			if(0 <= k && k <= 200) {
				if(i >= 2) tb[i][j][k] |= tb[i-1][j][k];
				if(j >= 2) tb[i][j][k] |= tb[i][j-1][k];
				if(k >= 2) tb[i][j][k] |= tb[i][j][k-1];
				if(i >= 1 && j >= 1) tb[i][j][k] |= tb[i-1][j-1][k+1];
				if(j >= 1 && k >= 1) tb[i][j][k] |= tb[i+1][j-1][k-1];
				if(k >= 1 && i >= 1) tb[i][j][k] |= tb[i-1][j+1][k-1];
			}
		}
	}

	for(int j = 0; j < 3; j++)
		if(tb[cnt[0]][cnt[1]][cnt[2]] & (1<<j))
			printf("%c", "BGR"[j]);



    return 0;
}
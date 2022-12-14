#define _CRT_SECURE_NO_WARNINGS

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
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 105;

int N;
vector<int> S;
int resA, resB;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int c; scanf("%d" ,&c);
		for(int t = 0; t < c; t++) {
			int v; scanf("%d", &v);
			if(t < c/2) resA += v;
			else if(t > c/2 || c % 2 == 0) resB += v;
			else S.push_back(v);
		}
	}

	sort(S.begin(), S.end(), greater<int>());
	for(int i = 0; i < S.size(); i++) (!(i%2) ? resA : resB) += S[i];

	printf("%d %d\n", resA, resB);
	return 0;
}
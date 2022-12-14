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

const int N_ = 1000005;
char A[N_], B[N_];
int AN, BN, N;
bool T[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 1, 1},
	{0, 1, 1, 1},
	{0, 1, 1, 1}
};

void answer (bool r) {
	puts(r ? "YES" : "NO");
	exit(0);
}

int main() {
	int i, j, k;

	scanf("%s%s", A+1, B+1);
	AN = strlen(A+1);
	BN = strlen(B+1);

	if(AN != BN) answer(0);
	if(AN == 1) answer(A[1] == B[1]);
	
	bool az = true, bz = true;
	for(i = 1; i <= AN; i++) if(A[i] == '1') az = false;
	for(i = 1; i <= BN; i++) if(B[i] == '1') bz = false;

	answer(!(az ^ bz));

	return 0;
}
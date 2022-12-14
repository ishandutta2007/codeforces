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

char D[25][25];
char A[25][25];
int res=100;

int main() {
	int i,j,k,t;
	for(i=0; i<8; i++) scanf("%s",D[i]);
	
	for(i=0; i<(1<<8); i++) {
		for(j=0; j<(1<<8); j++) {
			int tmp = 0;
			for(k = 0; k < 8; k++) {
				for(t = 0; t < 8; t++) A[k][t] = 'W';
			}
			
			for(k = 0; k < 8; k++) if(i & (1<<k)) {
				for(t = 0; t < 8; t++) A[t][k] = 'B';
				++tmp;
			}
			for(k = 0; k < 8; k++) if(j & (1<<k)) {
				for(t = 0; t < 8; t++) A[k][t] = 'B';
				++tmp;
			}
			bool pos = true;
			for(k = 0; k < 8; k++) {
				for(t = 0; t < 8; t++) if(D[k][t] != A[k][t]) pos = false;
			}
			if(pos) res = min(res, tmp);
		}
	}
	printf("%d\n",res);
	return 0;
}
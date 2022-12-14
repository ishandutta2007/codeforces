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


int main() {
	int i, j, k;

	int n;
	while(scanf("%d",&n) == 1) {
		for(i = 0; i <= n; i++) {
			for(j = 0; j < n*2+1; j++) {
				char ch = -1;
				if(j < n-i) ch = ' ';
				else if(j < n) ch = j-(n-i) + '0';
				else if(j <= n+i) ch = (n+i)-j + '0';
				else { puts(""); break; }
				if(j != 0) putchar(' ');
				putchar(ch);
			}
		}puts("");
		for(i = n-1; i >= 0; i--) {
			for(j = 0; j < n*2+1; j++) {
				char ch = -1;
				if(j < n-i) ch = ' ';
				else if(j < n) ch = j-(n-i) + '0';
				else if(j <= n+i) ch = (n+i)-j + '0';
				else { puts(""); break; }
				if(j != 0) putchar(' ');
				putchar(ch);
			}
		}
	}
	return 0;
}
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200
#define mod 1000000007

typedef long long ll;
using namespace std;

char str[4];
char A[3];
char B[3];

main(){

	scanf(" %c %c %c %c",&str[0],&str[1],&str[3],&str[2]);

	int i = 0;
	while(str[i] != 'A') i++;
	int u = 0;
	for(int j=0;j<4;j++){
		if(str[(i+j)%4] != 'X')
			A[u++] = str[(i+j)%4];
	}

	scanf(" %c %c %c %c",&str[0],&str[1],&str[3],&str[2]);

	 i = 0;
	while(str[i] != 'A') i++;
	 u = 0;
	for(int j=0;j<4;j++){
		if(str[(i+j)%4] != 'X')
			B[u++] = str[(i+j)%4];
	}

	if(A[0] == B[0] && A[1] == B[1]  && A[2] == B[2])
		printf("YES\n");
	else
		printf("NO\n");

}
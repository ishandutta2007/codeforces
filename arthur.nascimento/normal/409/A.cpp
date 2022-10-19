#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

char A[30];
char B[30];

main(){

	int a=0,b=0;
	scanf(" %s %s",A,B);
	int n = strlen(A)/2;

	for(int i=0;i<n;i++){

		if(A[2*i] == B[2*i])
			continue;
		if(A[2*i] == '[')
			if(B[2*i] == '8')
				b++;
			else
				a++;
		if(A[2*i] == '8')
			if(B[2*i] == '[')
				a++;
			else
				b++;
		if(A[2*i] == '(')
			if(B[2*i] == '[')
				b++;
			else
				a++;
			}

	if(a == b)
		printf("TIE\n");
	if(a > b)
		printf("TEAM 1 WINS\n");
	if(a < b)
		printf("TEAM 2 WINS\n");




		}
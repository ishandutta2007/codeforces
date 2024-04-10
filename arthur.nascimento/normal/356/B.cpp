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

int gr[1001000];

int qnt[26][1001000];

char A[1001000];
char B[1001000];

long long gcd(long long a,long long b){
	return b ? gcd(b,a%b) : a;}

main(){

		long long n,m,a,b;
		
		scanf("%I64d%I64d",&n,&m);
		scanf(" %s %s",A,B);

		a = strlen(A);
		b = strlen(B);

		int q = 1;

		for(int i=0;i<a;i++)
			if(!gr[i]){

				gr[i] = q;

				qnt[A[i]-'a'][q]++;

				for(int j=(i+b)%a; j != i; j = (j+b)%a)
					gr[j] = q,
					qnt[A[j]-'a'][q]++;

				q++;

			}

		long long ans = 0;
		
		for(int i=0;i<b;i++)
			for(int j=0;j<26;j++)
				if(j != B[i]-'a')
					ans += qnt[j][gr[i%a]];

		printf("%I64d\n",ans * ((n*gcd(a,b))/b));

}
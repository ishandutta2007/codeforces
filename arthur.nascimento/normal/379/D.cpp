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

long long fib[60];

long long qbb[60];

void print(int n,int ansA,char ai,char af){

	debug("print n=%d ansA=%d ai=%c af=%c\n",n,ansA,ai,af);

	printf("%c",ai);
	int foi = 1;

	if(n == 1){
		printf("\n");
		return;

		}

	if(ansA && ai == 'A'){
		printf("C");
		ansA--;
		foi++;

		if(n == 2){
			printf("\n");
			return;
			}
		}

	debug("foi=%d ansA=%d\n",foi,ansA);

	for(;foi<n-2 && ansA;foi+=2){
		printf("AC");
		ansA--;
		}

	if(foi == n-2 && ansA == 1){
		printf("A"),
		ansA--,
		foi++;
		assert(af == 'C');
		}

	while(foi < n-1)
		foi++,
		printf("B");

	printf("%c\n",af);

}

main(){

		fib[1] = 1;
		fib[2] = 1;

		for(int i=3;i<60;i++)
			fib[i] = fib[i-1] + fib[i-2];

		qbb[1] = qbb[2] = 0;

		for(int i=3;i<60;i++){

			qbb[i] = qbb[i-1] + qbb[i-2];

			if(i%2)
				qbb[i]++;
			}

		int k,x,n,m;

		scanf("%d%d%d%d",&k,&x,&n,&m);

		long long qA = fib[k-2];
		long long qB = fib[k-1];
		long long qAB = fib[k-2];
		long long qBB = qbb[k-2];
		long long qBA = qB - qBB - 1;

		debug("qA=%I64d qB=%I64d qAb=%I64d qBB=%I64d qBA=%I64d\n",qA,qB,qAB,qBB,qBA);

		for(char ai='A'; ai<='C'; ai++)
			for(char af='A'; af<='C'; af++)
				for(char bi='A'; bi<='C'; bi++)
					for(char bf='A'; bf<='C'; bf++){
						
						if(n == 1 && ai != af)
							continue;
						if(m == 1 && bi != bf)
							continue;

						long long u = x;

						if(af == 'A' && bi == 'C')
							u -= qAB;

						if(bf == 'A' && bi == 'C')
							u -= qBB;

						if(bf == 'A' && ai == 'C')
							u -= qBA;

						int minA = 0;

						if(n == 2 && ai == 'A' && af == 'C')
							minA++;

						int maxA = (n - ((ai!='A')?1:0) - ((af!='C')?1:0))/2;

						int minB = 0;

						if(m == 2 && bi == 'A' && bf == 'C')
							minB++;

						int maxB = (m - ((bi!='A')?1:0) - ((bf!='C')?1:0))/2;

						debug("B = %c..%c min=%d max=%d\n",bi,bf,minB,maxB);

						for(long long i=minA;i<=maxA;i++){

								if( (u - i*qA) % qB == 0 && u >= i*qA)

									if(((u-i*qA)/qB) >= minB && ((u-i*qA)/qB) <= maxB){

										long long ansA = i;
										long long ansB = (u-i*qA)/qB;

										print(n,ansA,ai,af);
										print(m,ansB,bi,bf);

										/*printf("%c",ai);
										int foi = 1;	

										if(ansA && ai == 'A'){
											printf("C");
											ansA--;
											foi++;
											}

										for(;foi<ansA-2 && ansA;foi+=2){
											printf("AC\n");
											ansA--;
											}*/
									
										return 0;
										}

									}

								}

						
		printf("Happy new year!\n");						
}
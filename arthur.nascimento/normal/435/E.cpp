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
#define eps 1e-12
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

char v[1010][1010];
char ans[1010][1010];

int a[1010];
int b[1010];

main(){

		int n,m;
		scanf("%d%d",&n,&m);
		getchar();

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				scanf("%c",&v[i][j]), v[i][j] -= '0';
			getchar();
		}

				
		int p[] = {1,2,3,4};

		do {

			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			int imp = 0;

			int ff = (p[0] == 1 && p[1] == 3 && p[2] == 2 && p[3] == 4);

			for(int i=0;i<n;i++){

				if(ff)
					debug("i=%d\n",i);
				int A,B;
				if(i%2 == 0)
					A = p[0], B = p[1];
				else
					A = p[2], B = p[3];
					
				for(int j=0;j<m;j++){
					if(v[i][j] != 0 && v[i][j] != A && v[i][j] != B)
						imp = 1;
					if(v[i][j] == A && (j%2 == 0))
						a[i] = 1;
					if(v[i][j] == B && (j%2 == 1))
						a[i] = 1;
					if(v[i][j] == B && (j%2==0))
						b[i] = 1;
					if(v[i][j] == A &&(j%2==1))
						b[i] = 1;
					
				}

			if(ff)
			debug("a = %d b = %d\n",a[i],b[i]);

			if(a[i] && b[i])
				imp = 1;
			if((!a[i]) && (!b[i]))
				a[i] = 1;

			}

			if(!imp){

				for(int i=0;i<n;i++){
					int A,B;
				if(i%2 == 0)
					A = p[0], B = p[1];
				else
					A = p[2], B = p[3];
				if(b[i])
					swap(A,B);
				for(int j=0;j<m;j++){
					printf("%c",'0' + ((j%2) ? B : A));
					assert(((j%2) ? B : A) == v[i][j] || v[i][j] == 0);
				}
				printf("\n");
				}
			return 0;
			}
			

		}

		while(next_permutation(p,p+4));

		for(int i=0;i<4;i++)
			p[i] = i+1;

		do {

			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			int imp = 0;

			for(int i=0;i<m;i++){
			
				int A,B;
				if(i%2 == 0)
					A = p[0], B = p[1];
				else
					A = p[2], B = p[3];
					
				for(int j=0;j<n;j++){
					if(v[j][i] != 0 && v[j][i] != A && v[j][i] != B)
						imp = 1;
					if(v[j][i] == A && (j%2 == 0))
						a[i] = 1;
					if(v[j][i] == B && (j%2 == 1))
						a[i] = 1;
					if(v[j][i] == B && (j%2==0))
						b[i] = 1;
					if(v[j][i] == A &&(j%2==1))
						b[i] = 1;
				}

			if(a[i] && b[i])
				imp = 1;
			if((!a[i]) && (!b[i]))
				a[i] = 1;

			}

			if(!imp){

				for(int i=0;i<m;i++){
					int A,B;
				if(i%2 == 0)
					A = p[0], B = p[1];
				else
					A = p[2], B = p[3];
				if(b[i])
					swap(A,B);
				for(int j=0;j<n;j++){
					ans[j][i] = '0'+((j%2) ? B : A);
					//printf("%c",'0'+((j%2) ? B : A));
					assert(((j%2) ? B : A) == v[j][i] || v[j][i] == 0);
					}
				//printf("\n");
				}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					printf("%c",ans[i][j]);
				printf("\n");}
			return 0;
			}
			

		}

		while(next_permutation(p,p+4));

		printf("0\n");

}
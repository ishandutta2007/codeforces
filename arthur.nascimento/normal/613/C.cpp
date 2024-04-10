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
#define mod 1000000007
#define maxn 2020
#define sq(x) ((x)*(x))

using namespace std;

int f[30];

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

main(){

	int n;
	scanf("%d",&n);

	int odd = -1;
	int imp = 0;
	int g = 0;

	for(int i=0;i<n;i++){
		scanf("%d",f+i);
		if(f[i]%2 == 1){
			if(odd+1)
				imp = 1;
			odd = i;
		}
		g = gcd(f[i],g);
	}

	if(imp){
		printf("0\n");
		for(int i=0;i<n;i++)
			for(int j=0;j<f[i];j++)
				printf("%c",i+'a');
		printf("\n");
		return 0;
	}
	if(g%2 == 0){
		printf("%d\n",g);
		for(int i=0;i<n;i++)
			f[i] /= g;
		for(int i=0;i<g;i++){
			if(i%2 == 0)
				for(int j=0;j<n;j++)
					for(int k=0;k<f[j];k++)
						printf("%c",j+'a');
			else
				for(int j=n-1;j>=0;j--)
					for(int k=0;k<f[j];k++)
						printf("%c",j+'a');
		}
		printf("\n");
	}
	else {
		printf("%d\n",g);
		f[odd] -= g;
		for(int i=0;i<n;i++)
			f[i] /= g;
		for(int i=0;i<g;i++){
			printf("%c",odd+'a');
			for(int j=0;j<n;j++)
				for(int k=0;k<f[j]/2;k++)
					printf("%c",j+'a');
			for(int j=n-1;j>=0;j--)
				for(int k=0;k<f[j]/2;k++)
					printf("%c",j+'a');
		}
		printf("\n");
	}

}
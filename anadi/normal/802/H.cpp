#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int poly(int n)
{
	return (n*n*n+3*n*n+2*n)/6;
}
int n;
int val[N];
int main()
{
	scanf("%d",&n);
	int ile_bedzie=38;
	//printf("%d\n",poly(1));
	int znaki=0;
	val[1]=1; for(int i=1; i<=1000; ++i) val[i]=val[i-1]+poly(i);
	while(ile_bedzie>0)
	{
		while(n>=val[ile_bedzie])
		{
			printf("a");znaki++;
			n-=val[ile_bedzie];
		}
		ile_bedzie--;
		printf("bcde");znaki+=4;
	}
	printf(" abcde\n");
	fprintf(stderr,"znaki=%d\n",znaki);
}
//Tanuj Khattar

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
typedef vector< vi > 	vvi;
#define lli long long int
#define ulli unsigned long long int

#define pb push_back
#define F first
#define S second

#define gu getchar
#define pu putchar
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define INF 1000000000  //1 billion (10^9) 

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int main()
{
	int n,l;
	din(n);
	din(l);
	vi ar(n);
	int i;
	for(i=0;i<n;i++)
		din(ar[i]);
	sort(ar.begin(),ar.end());
	double d=0;
	if(ar[0]!=0)
		d = ar[0]-0;
	if(ar[n-1]!=l)
		d = max(d,l-ar[n-1]);
	for(i=0;i<n-1;i++)
		d = max(d,((double)(ar[i+1]-ar[i]))/2);

	printf("%lf\n",d);
	return 0;
}
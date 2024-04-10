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

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int n;
	int i;
	int x,y;
	scanf("%d %d %d",&n,&x,&y);
	int f = gcd(x,y);
	int m;
	int xhit,yhit;
	for(i=1;!((x/i)==f && x%i ==0);i++);
	xhit=i;
	for(i=1;!((y/i)==f && y%i ==0);i++);
	yhit=i;


	int total = xhit + yhit;
	vi ar(total);

	lli n1=1,d1=xhit,n2=1,d2=yhit;
	for(i=0;i<total;i++)
	{
		if((d1*n2)<(d2*n1))
		{
			n2++;
			ar[i]=1;
		}
		else if((d1*n2)>(d2*n1))
		{
			n1++;
			ar[i]=0;
		}
		else
		{
			n1++;n2++;
			ar[i++]=2;
			ar[i]=2;
		}
	}

	for(i=0;i<n;i++)
	{
		din(m);
		m = m%total;
		
		if(m==0)
			m=total-1;
		else
			m=m-1;
		switch(ar[m])
		{
			case 0 : printf("Vanya\n");
				 break;
			case 1 : printf("Vova\n");
				 break;
			case 2 : printf("Both\n");
				 break;
		}
		
	}


	return 0;
}
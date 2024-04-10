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
	long long int n,r,avg;
	scanf("%lld %lld %lld",&n,&r,&avg);
	long long int i;
	vii arr(n);
	long long int cavg=0;
	long long int ans;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].S,&arr[i].F);
		cavg+=arr[i].S;
	}
	if(cavg >= (avg*n))
		ans=0;
	else
	{
		long long int k=(avg*n)-cavg;
		sort(arr.begin(),arr.end());
		ans=0;
		for(i=0;k>0 && i<n;i++)
		{
			long long int temp = r - arr[i].S;
			if(k>=temp)
			{
				k = k-temp;
				ans += arr[i].F*temp;
			}
			else
			{
				ans += arr[i].F*(k);
				k=0;
			}
		}
	}
	lldout(ans);



	return 0;
}
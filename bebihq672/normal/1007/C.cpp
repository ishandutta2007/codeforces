#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%I64d",&n);
	long long al=1,ar=n,bl=1,br=n,arr=n,brr=n;
	while(1)
	{
		long long tmpa,tmpb;
		tmpa=(al+arr)/2;
		tmpb=(bl+brr)/2;
		
		if(double(ar-arr)*(brr-bl+1)>double(arr-al+1)*(br-bl+1))
			tmpa=arr;
		if(double(br-brr)*(arr-al+1)>double(brr-bl+1)*(ar-al+1))
			tmpb=brr;
		printf("%I64d %I64d\n",tmpa,tmpb);
		fflush(stdout);
		int res;
		scanf("%d",&res);
		if(res==0)
			break;
		if(res==1)
			al=tmpa+1;
		else if(res==2)
			bl=tmpb+1;
		else
		{
			arr=tmpa-1;
			brr=tmpb-1;
		}
		if(arr<al)
		{
			br=brr;
			arr=ar;
		}
		if(brr<bl)
		{
			ar=arr;
			brr=br;
		}
	}
	return 0;
}
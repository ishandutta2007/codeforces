#include<bits/stdc++.h>
using namespace std;
int guess(long long l,long long r)
{
	printf("%I64d %I64d\n",l,r);
	fflush(stdout);
	char res[5];
	scanf("%s",res);
	if(res[0]=='Y')
	{
		if(l==r)
			exit(0);
		return 1;
	}
	else
		return 0;
}
long long prand()
{
	while(1)
	{
		int tmp=rand();
		if(tmp>=0)
			return tmp;
	}
}
long long getarand()
{
	return prand()|(prand()<<15)|(prand()<<30)|(prand()<<45);
}
int main()
{
	srand(time(0));
	long long R,k;
	scanf("%I64d%I64d",&R,&k);	
	long long l=1,r=R;
	while(1)
	{
		if(r-l+1<=6*k+1)
		{
			long long tmp=l+getarand()%(r-l+1);
			guess(tmp,tmp);
		}
		else
		{
			long long m=(l+r)/2;
			if(guess(l,m)==1)
				r=m;
			else
				l=m+1;
		}
		l-=k;
		r+=k;
		l=max(l,1ll);
		r=min(r,R);
	}
	return 0;
}
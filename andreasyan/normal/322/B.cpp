#include <iostream>
#include <algorithm>
using namespace std;

int res,x[3];
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a%3==0 && a>0)
	{
		res+=a/3-1;
		x[0]=3;
	}
	else if(a%3!=0 && a>0)
	{
		res+=a/3;
		x[0]=a%3;
	}
	if(a==0)
		x[0]=0;
	//
	if(b%3==0 && b>0)
	{
		res+=b/3-1;
		x[1]=3;
	}
	else if(b%3!=0 && b>0)
	{
		res+=b/3;
		x[1]=b%3;
	}
	if(b==0)
		x[1]=0;
	//
	if(c%3==0 && c>0)
	{
		res+=c/3-1;
		x[2]=3;
	}
	else if(c%3!=0 && c>0)
	{
		res+=c/3;
		x[2]=c%3;
	}
	if(c==0)
		x[2]=0;
	sort(x,x+3);
	if(x[0]==2)
		res+=2;
	if(x[0]==3)
		res+=3;
	if(x[0]==1)
	{
		if(x[1]==3 && x[2]==3)
			res+=2;
		else
			res++;
	}
	if(x[0]==0)
	{
		if(x[1]==3 && x[2]!=3)
			res++;
		if(x[2]==3 && x[1]!=3)
			res++;
		if(x[1]==3 && x[2]==3)
			res+=2;
	}
	cout<<res<<endl;
	return 0;
}
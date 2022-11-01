#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (101*1000)

ll x[3],y[3],s;

void out2(ll z,ll a,ll b,ll h,char c1,char c2,char c3)
{
	cout<<z<<"\n";
	int i;
	for(i=0;i<h;i++)
	{
		for(int j=0;j<s/z;j++)
		{
			if(j<a)
				cout<<c1;
			else
				cout<<c2;	
		}
		cout<<"\n";
	}
	for(;i<z;i++)
	{
		for(int j=0;j<z;j++)
			cout<<c3;
		cout<<"\n";	
	}
	exit(0);
}

void out3(ll z,ll a,ll b,ll c)
{
	cout<<z<<endl;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<z;j++)
			cout<<'A';
		cout<<"\n";	
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<z;j++)
			cout<<'B';
		cout<<"\n";	
	}
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<z;j++)
			cout<<'C';
		cout<<"\n";	
	}
	exit(0);
}

void check2(ll z,ll a,ll b,ll c,ll d,ll e,ll f,char c1,char c2,char c3)
{
	
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(a,d);	
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(b,e);
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(a,d);
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(b,e);
	swap(c,f);
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(a,d);	
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(b,e);
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(a,d);
	if(a+b==z && c==z && d==e && d+f==z)
		out2(z,a,b,d,c1,c2,c3);
	swap(b,e);
				
	
}

int main()
{
    for(int i=0;i<3;i++)cin>>x[i]>>y[i],s+=x[i]*y[i];
    if(s%(ll)sqrt(s)!=0)
    	return cout<<-1,0;
    //cout<<s<<endl;
    check2(sqrt(s),x[0],x[1],x[2],y[0],y[1],y[2],'A','B','C');
    check2(sqrt(s),x[2],x[1],x[0],y[2],y[1],y[0],'C','B','A');
	check2(sqrt(s),x[0],x[2],x[1],y[0],y[2],y[1],'A','C','B');
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(((i)?x[0]:y[0])==((j)?x[1]:y[1]) && ((i)?x[0]:y[0])==((k)?x[2]:y[2]) && ((i)?x[0]:y[0])==sqrt(s))
					out3(sqrt(s),((!i)?x[0]:y[0]),((!j)?x[1]:y[1]),((!k)?x[2]:y[2]));
			}
		}
	}
	cout<<-1;
	return 0;
}
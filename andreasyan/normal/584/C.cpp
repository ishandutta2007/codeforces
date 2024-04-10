#include <iostream>
using namespace std;

int n,m,k,t;
bool z;
char a[100005],b[100005],c[100005];
int main()
{
	int i,j,k1,k2;
	cin>>n>>t;
	cin>>a>>b;
	k=n-t;
	for(i=0;i<n;i++)
		if(a[i]==b[i])
			m++;
///////////////////////////////////////////////////////
	if(m>=k)
	{
		for(i=0;i<n;i++)
		{
			if(k==0)
			z=true;
			if(a[i]==b[i] && z==false)
			{
				c[i]=a[i];
				k--;
			}
			if(a[i]!=b[i] || z==true)
				c[i]='0';
		}
		for(i=0;i<n;i++)
		{
			if(c[i]=='0')
			{
				if(a[i]!='a' && b[i]!='a')
					c[i]='a';
				if(a[i]!='b' && b[i]!='b')
					c[i]='b';
				if(a[i]!='c' && b[i]!='c')
					c[i]='c';
			}
		}
		for(i=0;i<n;i++)
			cout<<c[i];
		cout<<endl;
		return 0;
	}
	else
	{
		if((n-m)/2+m<k)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i] && z==false)
			{
				c[i]=a[i];
				k--;
			}
		}
		k1=k;
		k2=k;
		for(i=0;i<n;i++)
		{
			if(k1==0 && k2==0)
				z=true;
			if(a[i]!=b[i] && z==false)
			{
				if(k1>=k2)
				{
					k1--;
					c[i]=a[i];
					continue;
				}
				if(k1<k2)
				{
					k2--;
					c[i]=b[i];
				}
			}
			if(z==true && a[i]!=b[i])
			{
				if(a[i]!='a' && b[i]!='a')
					c[i]='a';
				if(a[i]!='b' && b[i]!='b')
					c[i]='b';
				if(a[i]!='c' && b[i]!='c')
					c[i]='c';
			}
		}
		for(i=0;i<n;i++)
			cout<<c[i];
		cout<<endl;
	}
	return 0;
}
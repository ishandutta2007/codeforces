#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
string s;
int n;
int main()
{
	cin>>n>>s;
	for(int i=25;i>=1;i--)
	{
		while(!s.empty())
		{
			bool flag=1;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]==i+'a')
				{
					if(j&&s[j-1]==(i-1)+'a')
					{
						flag=0;
						s.erase(s.begin()+j);
						break;
					}
					else if(j+1!=s.size()&&s[j+1]==(i-1)+'a')
					{
						flag=0;
						s.erase(s.begin()+j);
						break;
					}
				}
			}
			if(flag)break;
		}
	}
	cout<<n-s.size();
	return 0;
}
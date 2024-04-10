#include <bits/stdc++.h>

using namespace std;

int gh;
long long n, a, akt, lb, licz, ret, p, k, s;
vector <long long> v;

void pri(long long x)
{
	cout<<"? "<<x<<endl;
}

int main()
{
	cin>>gh;
	for(int hg=0; hg<gh; ++hg)
	{
		cin>>n;
		a=n;
		lb=0;
		while(a)
		{
			++lb;
			a>>=1;
		}
		p=1;
		k=n+1;
		s=(p+k)>>1;
		v.clear();
		while(p<s)
		{
			v.push_back(s);
			p=s;
			s=(p+k)>>1;
		}
		reverse(v.begin(), v.end());
		akt=1;
		licz=0;
		for(auto i:v)
		{
			if(licz)
			{
				akt-=i-1;
			}
			else
			{
				akt+=i-1;
			}
			licz^=1;
		}
		pri(akt);
		cin>>licz;
		if(akt<=n/2)
		{
			licz=0;
		}
		else
		{
			licz=1;
		}
		p=1;
		k=n+1;
		s=(p+k)>>1;
		while(p<s)
		{
			if(licz)
			{
				akt-=s-1;
			}
			else
			{
				akt+=s-1;
			}
			pri(akt);
			cin>>ret;
			if(ret)
			{
				k=s;
			}
			else
			{
				p=s;
			}
			s=(p+k)>>1;
			licz^=1;
		}
		cout<<"= "<<p<<endl;
	}
	return 0;
}
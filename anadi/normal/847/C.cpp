#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6;

int ile[maxn];
typedef long long LL;

void rek(int x)
{
	if(ile[x]==0)
		return ;
	cout<<"(";
	rek(x+1);
	cout<<")";
	for(int i=1;i<ile[x];i++)
		cout<<"()";
}

int main()
{
	LL n,k;
	cin>>n>>k;
	n--;
	ile[0]=1;
	int ma=0;
	for(int i=0;i<n;i++)
	{
		if(k==0)
		{
			ile[0]++;
			continue;
		}
		if(k>=ma+1)
		{
			ile[ma+1]++;
			k-=ma+1;
			ma++;
		}
		else
		{
			ile[k]++;
			k=0;
		}
		
	}
	if(k>0)
		cout<<"Impossible";
	else
		rek(0);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, ctplus=0, ctminus=0, possible=0;
int a[N], criminal[N], notCriminal[N], possibleCriminal[N];
char type[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>type[i];
		cin>>a[i];
		if(type[i]=='+')
		{
			ctplus++;
			criminal[a[i]]++;
		}
		else
		{
			ctminus++;
			notCriminal[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int truth=criminal[i];
		truth+=ctminus-notCriminal[i];
		if(truth==m)
		{
			possible++;
			possibleCriminal[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(type[i]=='+')
		{
			if(possibleCriminal[a[i]])
			{
				if(possible==1)
					cout<<"Truth"<<endl;
				else
					cout<<"Not defined"<<endl;
			}
			else
				cout<<"Lie"<<endl;
		}
		else
		{
			if(possibleCriminal[a[i]])
			{
				if(possible==1)
					cout<<"Lie"<<endl;
				else
					cout<<"Not defined"<<endl;
			}
			else
				cout<<"Truth"<<endl;
		}
	}
	return 0;
}
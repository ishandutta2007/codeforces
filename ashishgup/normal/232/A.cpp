#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=105;

int a[N][N];

int nC2(int k)
{
	return k*(k-1)/2;
}

int nC3(int k)
{
	return k*(k-1)*(k-2)/6;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int reqd=0, three=0;
    for(int i=3;i<=100;i++)
    {
    	if(nC3(i)<=n)
    	{
    		three=i;
    	}
    }
    reqd=three;
    n-=nC3(three);
    for(int i=1;i<=three;i++)
    {
    	for(int j=1;j<=three;j++)
    	{
    		if(i!=j)
    			a[i][j]=1;
    	}
    }
    while(n)
    {
    	int two=0;
    	for(int i=2;i<=three;i++)
    	{
    		if(nC2(i)<=n)
    		{
    			two=i;
    		}
    	}
    	n-=nC2(two);
    	reqd++;
    	for(int i=1;i<=two;i++)
    	{
    		a[i][reqd]=a[reqd][i]=1;
    	}
    }
    cout<<reqd<<endl;
    for(int i=1;i<=reqd;i++)
    {
    	for(int j=1;j<=reqd;j++)
    	{
    		cout<<a[i][j];
    	}
    	cout<<endl;
    }
    return 0;
}
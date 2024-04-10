#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e2+5;

int a[N][N];

int32_t main()
{
    IOS;
    int n, m, k;
    cin>>n>>m>>k;
    int ans1=0, ans2=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
    	}
    }
    for(int j=1;j<=m;j++)
    {
    	int count=0, score=0, storecount=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(!a[i][j])
    			continue;
    		int curscore=0;
    		for(int p=i;p<=n&&p<i+k;p++)
    		{
    			curscore+=a[p][j];
    		}
    		if(curscore>score)
    		{
    			score=curscore;
    			storecount=count;
    		}
    		count++;
    	}
    	ans1+=score;
    	ans2+=storecount;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
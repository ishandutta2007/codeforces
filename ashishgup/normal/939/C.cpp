#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, s, f;
int a[N];

int getval(int k)
{
	int vali=(k-(s-1));
	if(vali<=0)
		vali+=n;
	int tim=1-(vali-1);
	if(tim<=0)
		tim+=n;
	return tim;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    {
    	a[i]=a[i-n];
    }
    cin>>s>>f;
    int range=f-s;
    int max1=0, cur=0;
    int ans=1;
    for(int i=1;i<=range;i++)
    {
    	max1+=a[i];
    	cur+=a[i];
    }
    int original=max1;
    for(int i=2;i<=n;i++)
    {
    	cur-=a[i-1];
    	cur+=a[i+range-1];
    	if(cur>=max1)
    	{
    		max1=cur;
    		ans=i;
    	}
    }
    cur=0;
    for(int i=1;i<=range;i++)
    {
    	cur+=a[i];
    }
    vector<int> posans;
    if(cur==max1)
    	posans.push_back(getval(1));
    for(int i=2;i<=n;i++)
    {
    	cur-=a[i-1];
    	cur+=a[i+range-1];
    	if(cur==max1)
    	{
    		int tim=getval(i);
    		posans.push_back(tim);
    	}
    }
    sort(posans.begin(), posans.end());
   	cout<<posans[0];
    return 0;
}
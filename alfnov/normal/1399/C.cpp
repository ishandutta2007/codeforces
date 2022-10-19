#include<bits/stdc++.h>
using namespace std;
int w[55];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>w[i];
		sort(w+1,w+n+1);
		int mx=n<<1,ans=0;
		for(int s=2;s<=mx;s++)
		{
			int l=1,r=n,anss=0;
			while(l<r)
			{
				if(w[l]+w[r]>s)r--;
				else if(w[l]+w[r]<s)l++;
				else anss++,l++,r--;
			}
			ans=max(ans,anss);
		}
		cout<<ans<<endl;
	}
	return 0;
}
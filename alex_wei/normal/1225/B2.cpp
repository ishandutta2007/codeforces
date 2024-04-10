#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,d,t,a[1000002],cnt[1000002];
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>k>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int l=1,r=d,dif=0,ans=1e9;
		for(int i=1;i<d;i++){
			if(!cnt[a[i]])dif++;
			cnt[a[i]]++;
		}
		for(int i=d;i<=n;i++){
			if(!cnt[a[i]])dif++;
			cnt[a[i]]++;
			ans=min(ans,dif);
			if(cnt[a[i-d+1]]==1)dif--;
			cnt[a[i-d+1]]--;
		}
		for(int i=n-d+2;i<=n;i++)
			cnt[a[i]]--;
		cout<<ans<<endl;
	}
    return 0;
}
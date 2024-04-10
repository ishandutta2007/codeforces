#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[200005],pd[200005];
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],pd[i]=0;
		int ans=n+1;
		for(int i=1;i<=n;i++){
			if(pd[a[i]])
				ans=min(ans,i-pd[a[i]]+1);
			pd[a[i]]=i;
		}
		if(ans>n)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
    return 0;
}
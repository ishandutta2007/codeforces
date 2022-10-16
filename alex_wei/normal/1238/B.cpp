#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n,r,a[100005],pd[100005];
int main()
{
	cin>>q;
	for(int l=0;l<q;l++){
		cin>>n>>r;
		for(int i=1;i<=n;i++)
			cin>>a[i],pd[i]=1;
		sort(a+1,a+n+1);
		ll ans=0,delta=0,m=unique(a+1,a+n+1)-a-1,i;
		for(i=m;i>0&&a[i]-delta>0;i--){
			delta+=r;
			ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}
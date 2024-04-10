#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum,a[100005],cnt=1e12;
vector <ll> q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i])q.push_back(i);
	}
	if(sum<2)cout<<"-1",exit(0);
	for(int j=2;j<=sum;j++)
		if(sum%j==0){
			ll tim=sum/j,ans=0;
			for(int i=0;i<tim;i++)
				for(int k=0;k<j;k++)
					ans+=abs(q[i*j+k]-q[i*j+j/2]);
			cnt=min(cnt,ans);
		}
	cout<<cnt<<endl;
    return 0;
}
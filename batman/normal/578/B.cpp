#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (201*1000)
#define M (110)
ll n,k,x,a[N],bit[M],ans,tvn=1;

int main()
{
    cin>>n>>k>>x;
    for(int i=0;i<k;i++)tvn*=x;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	ll ex=a[i],p=0;
    	while(ex)
    		bit[p++]+=(ex&1),ex/=2;
	}
	for(int i=0;i<n;i++)
	{
		ll ex=a[i],p=0,num=0;
    	while(ex)
    		bit[p++]-=(ex&1),ex/=2;
    	for(int j=0,t=1;j<M;j++,t<<=1)
			num+=((bit[j])?t:0);
		ans=max(ans,num|(a[i]*tvn));
		p=0;
    	while(a[i])
    		bit[p++]+=(a[i]&1),a[i]/=2;			
	}
	cout<<ans<<endl;
    return 0;
}
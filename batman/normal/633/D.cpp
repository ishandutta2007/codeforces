#include <bits/stdc++.h>
using namespace std;
#define ll int
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1100)
#define K (2010)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N],ans;
unordered_map <ll,ll> mp,mp2;
map <pair<ll,ll>,bool> mp3;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j && !mp3[{a[i],a[j]}])
			{
				mp3[{a[i],a[j]}]=1;
				if(a[i]==0 && a[j]==0){ans=max(ans,mp[0]);continue;}
				ll ex,p=a[i],q=a[j],res=1;
				mp2.clear();
				mp2[p]++;mp2[q]++;
				while(mp2[q]<=mp[q])
					ex=q,q=p+q,p=ex,res++,mp2[q]++;
				ans=max(ans,res);
			}
	cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int n,m;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		map<int,int> M;
		cin>>n;
		ll sum=0;
		rep(i,1,n) cin>>a[i],M[a[i]]++,sum+=a[i];
		queue<ll> q; q.push(sum); int cnt=0;
		while(!q.empty()&&q.size()<=n)
		{
			ll p=q.front(); q.pop();
			if (M[p])
			{
				cnt++; M[p]--;
			} else
			{
				ll p1=p/2; ll p2=p-p1;
				q.push(p2); q.push(p1);
			}
		}
		if(cnt==n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
	return 0;
}
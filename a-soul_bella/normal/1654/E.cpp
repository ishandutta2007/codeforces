#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],s[100005];
const int B=612,qwq=100000/B+1;
const int MAXN=100005;
const int mod=100003;
const int BASE=22637261;
struct HASH{
	struct Edge{
		int val;
		signed cnt,nxt;
	}e[MAXN];
	signed head[mod],cnt = 0;
	inline int insert(int x){
		x ^= BASE;
		int b = (x%mod+mod)%mod;
		for(int i = head[b];i;i = e[i].nxt){
			if(e[i].val == x){
				return ++e[i].cnt;
			}
		}
		e[++cnt] = (Edge){x,1,head[b]};head[b] = cnt;
		return 1;
	}
	inline void clear()
	{
		memset(head,0,sizeof head);
		memset(e,0,sizeof e);
		cnt=0;
	}
}S;
inline int cal(int l,int r,int d)
{
	int rtn=0;
	S.clear();
	for(int i=l;i<=r;i++) rtn=max(rtn,S.insert(a[i]-i*d));
//	cout << S.cnt << "\n";
//		s[++cnt]=a[i]-i*d;
/*	sort(s+1,s+cnt+1);
	int now=1;
	int mx=1;
	for(int i=2;i<=cnt;i++)
	{
		if(s[i]==s[i-1]) ++now;
		else now=1;
		mx=max(mx,now);
	}*/
	return rtn;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=100000;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int ans=0;
	for(int i=-B;i<=B;i++)
		ans=max(ans,cal(1,n,i));
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=min(i+qwq,n);j++)
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				int d=(a[j]-a[i])/(j-i);
				int cnt=2,now=a[i];
				for(int k=i+1;k<j;k++)
					cnt+=((now+=d)==a[k]);
				ans=max(ans,cnt);
			}
		}
	}
	cout << n-ans;
	return 0;
}
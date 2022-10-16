#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
inline int read()
{
	bool f = 0;
	int s = 0; char c; while((c=getchar())<'0'||c>'9')if(c=='-')f=1;
	do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');
	return f?-s:s;
}
const int N = 200010;
typedef long long lint;
typedef pair<int,int> pii;
pii li[N];
lint ans,cnt,cnt2;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,i;
	n = read();
	for(i=1;i<=n;i++) li[i].first = read(), li[i].second = read();
	sort(li+1,li+1+n);
	cnt = 0; cnt2 = 0;
	for(i=1;i<=n;i++)
	{
		//cnt2++;
		//if(li[i]==li[i-1]) continue;
		if(li[i].first!=li[i-1].first)
		{
			ans += cnt*(cnt-1)/2;
			cnt = cnt = 0;
		}
		cnt++; 
	}
	ans += cnt*(cnt-1)/2;
	for(i=1;i<=n;i++) swap(li[i].first,li[i].second);
	sort(li+1,li+1+n);
	cnt = 0; cnt2 = 0;
	for(i=1;i<=n;i++)
	{
		//cnt2++;
		//if(li[i]==li[i-1]) continue;
		if(li[i].first!=li[i-1].first)
		{
			ans += cnt*(cnt-1)/2;
			cnt = cnt2 = 0;
		}
		cnt++;
	}
	ans += cnt*(cnt-1)/2;
	cnt = 0;
	for(i=1;i<=n;i++)
	{
		if(li[i]==li[i-1])
		{
			cnt++;
		}
		else
		{
			ans -= cnt*(cnt-1)/2;
			cnt = 1;
		}
	}
	ans -= cnt*(cnt-1)/2;
	printf("%I64d\n",ans);
	return 0;
}
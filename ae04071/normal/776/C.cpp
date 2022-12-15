#include <stdio.h>
#include <map>
#include <utility>

using lli = long long;
using ip=std::pair<lli, lli>;

int n;
lli k,arr[100001],sum[100001];
std::map<lli, lli> s;

lli power(lli a, lli t)
{
	lli res=1;
	while(t) {
		if(t&1) res*=a;
		t>>=1;
		a*=a;
	}
	return res;
}

int main()
{
	scanf("%d %lld", &n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",arr+i);
		sum[i]=sum[i-1]+arr[i];
	}

	lli cnt=0;
	s.insert(ip(0, 1));
	for(int i=1;i<=n;i++) {
		int j=0;
		if(k==1)
			cnt+=s[sum[i]-1];
		else if(k==-1)
			cnt+=s[sum[i]-1]+s[sum[i]+1];
		else {
			for(int j=0;j<100;j++) {
				lli val=power(k,j);
				if(val>=1e15) break;
				auto it=s.find(sum[i]-val);

				if(it!=s.end())
					cnt+=it->second;
			}
		}
		
		if(s.find(sum[i])==s.end())
			s.insert(ip(sum[i],1));
		else
			s[sum[i]]+=1;
	}

	printf("%lld\n",cnt);

	return 0;
}
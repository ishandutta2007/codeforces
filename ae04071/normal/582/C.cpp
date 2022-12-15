#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;

int n,a[200000];
priority_queue<int, vector<int>,greater<int>> que[400];
int su[400], cnt[400], fl[400];
map<int,int> div_idx;
int div_cnt;

lli f(int s) {
	div_idx[s] = div_cnt;
	vector<int> b(s,0);
	for(int i=0;i<n;i++) b[i%s] = max(b[i%s], a[i]);

	int f=-1;
	lli res=0;
	for(int i=0;i<n;i++) if(a[i]<b[i%s]) {
		f=i;
		break;
	}
	if(f==-1) {
		fl[div_cnt]=1;
		res=n;
	} else {
		for(int i=f,j=f;i<n+f;) {
			if(a[i%n] < b[i%s]) {
				i++;
				continue;
			}
			j=i;
			for(;j<n+f && a[j%n] >= b[j%s];j++);
			
			
			int l=j-i;
			if(l>=s) {
				que[div_cnt].push(l);
				su[div_cnt] += l;
				cnt[div_cnt]++;
				res += l-s+1;
			}
			i=j;
		}
	}
	
	div_cnt++;
	assert(div_cnt<=400);
	//printf("%d %lld\n",s,res);
	return res;
}
lli g(int s,int t) {
	int idx=div_idx[s];
	if(fl[idx]) return n;

	while(!que[idx].empty() && que[idx].top() < t) {
		int val=que[idx].top();que[idx].pop();
		su[idx] -= val; 
		cnt[idx]--;
	}
	return su[idx] - 1ll*(t-1)*cnt[idx];
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	lli res=0;
	for(int i=1;i<n;i++) if(__gcd(i,n)==i) {
		res = res + f(i);
	} else {
		res = res + g(__gcd(i,n),i);
	}
	printf("%lld\n",res);

	return 0;
}
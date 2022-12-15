#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

inline lli _abs(lli a) {return a<0 ? -a : a;}
inline int _abs(int a) {return a<0 ? -a : a;}

int n,m,k,a[100000];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	
	priority_queue<int,vector<int>,greater<int>> que;
	for(int i=0;i<n-1;i++) que.push(a[i+1]-a[i]-1);
	int ans=0;
	while(sz(que)>=k) {
		int cur=que.top();que.pop();
		ans += cur;
	}
	printf("%d\n",ans+n);

	return 0;
}
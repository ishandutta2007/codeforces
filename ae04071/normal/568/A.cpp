#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int MAX=2000000;
int pr_sum[2000001],pa_sum[2000001],p,q;
int vis[2000001];

bool check(int val) {
	vector<int> a,b;
	while(val) a.push_back(val%10),val/=10;
	b=a;
	reverse(b.begin(),b.end());
	return a==b;
}
int main() {
	scanf("%d%d",&p,&q);

	pa_sum[1] = 1;
	for(int i=2;i<=MAX;i++) {	
		if(!vis[i]) {
			for(lli j=1ll*i*i;j<=MAX;j+=i) vis[j]=1;
			pr_sum[i]=1;
		}
		if(check(i)) pa_sum[i] = 1;
	}
	for(int i=1;i<=MAX;i++) pr_sum[i]+=pr_sum[i-1],pa_sum[i]+=pa_sum[i-1];

	int n=0;
	for(int i=1;i<=MAX;i++) {
		if(pr_sum[i] <= (1ll*pa_sum[i]*p)/q) n=i;
	}
	if(!n) puts("Palindromic tree is better than splay tree");
	else printf("%d\n",n);

	return 0;
}
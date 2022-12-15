#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int cnt[10],n;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int  val;
		scanf("%1d",&val);
		if(val==8) cnt[0]++;
		else cnt[1]++;
	}
	int ans=0;
	for(int i=1;i<=cnt[0];i++) {
		if((n-i)/10<i) break;
		ans=i;
	}
	printf("%d\n",ans);
	
	return 0;
}
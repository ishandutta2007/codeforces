#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
const int inf=1e9+10;

int n,a[200000],vis[200000];
int main() {
	int f=0,mx,cnt=0;
	vector<int> zp;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",a+i);
		if(a[i]<0) {
			cnt++;
			if(!f) mx=a[i],f=1;
			else mx=max(mx,a[i]);
		} else if(a[i]==0) {
			zp.push_back(i);
			vis[i]=1;
		}
	}

	vector<pii> ans;
	if(cnt%2==1) {
		for(int i=0;i<n;i++) if(a[i]==mx) {
			zp.push_back(i);
			vis[i]=1;
			break;
		}
	}
	if(!zp.empty()) {
		sort(zp.begin(),zp.end());
		for(int i=0;i<sz(zp)-1;i++) ans.push_back(pii(zp[i]+1,zp.back()+1));
		if(sz(ans)<n-1) ans.push_back(pii(zp.back()+1,-1));
	}
	
	int s=n-1;
	for(;s>=0 && vis[s];s--);
	for(int j=s-1;j>=0;j--) if(!vis[j]) {
		ans.push_back(pii(j+1,s+1));
	}
		
	for(auto &it:ans) {
		if(it.second == -1) printf("2 %d\n",it.first);
		else printf("1 %d %d\n",it.first,it.second);
	}
	
	return 0;
}
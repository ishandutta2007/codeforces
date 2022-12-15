#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef long long lli;

vector<int> prime;
int vis[1000001];
int main() {
	for(int i=2;i<=1000000;i++) if(!vis[i]) {
		for(lli j=1ll*i*i;j<=1000000;j+=i) vis[j]=1;
		prime.push_back(i);
	}

	int test;
	scanf("%d",&test);
	while(test--) {
		lli a,b;
		scanf("%lld%lld",&a,&b);
		if(a-b!=1) puts("NO");
		else {
			int f=1;
			for(auto &it:prime) {
				if(it>=(a+b)) break;
				if((a+b)%it==0) {
					f=0;
					break;
				}
			}
			puts(f ? "YES" : "NO");
		}
	}

	return 0;
}
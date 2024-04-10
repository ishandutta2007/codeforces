#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
int n,vis[1001];

int main() {
	scanf("%d",&n);
	for(int i=2;i<=n;i++) if(!vis[i]) {
		for(int j=i*i;j<=n;j+=i)vis[j]=1;
	}

	set<int> tr;
	for(int i=2;i<=n;i++) {
		int mx=0,val=i;
		for(int j=2;j<=n;j++) if(!vis[j] && val%j==0) {
			int t=1;
			while(val%j==0) val/=j,t*=j;
			tr.insert(t);
		}
	}
	printf("%d\n",(int)tr.size());
	for(auto &it:tr) printf("%d ",it);
	
	return 0;
}
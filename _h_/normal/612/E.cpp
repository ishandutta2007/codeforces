#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
const int mxn = 1e6+3;
int main(){
	int p[mxn], q[mxn], n, cnt[mxn];
	memset(cnt,-1,sizeof(cnt));
	bool vis[mxn] = {};
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i),--p[i];
	rep(i,0,n) if(!vis[i]){
		int sz = 0, j = i;

		do {
			vis[j] = 1;
			++sz;
			j = p[j];
		} while(j != i);
		if(sz%2 == 1){
			int k = i;
			rep(_,0,sz/2+1) k = p[k];
			do {
				q[j] = k;
				k = p[k];
				j = p[j];
			} while(j != i);
		} else if(cnt[sz] == -1){
			cnt[sz] = i;
		} else {
			int k = cnt[sz];
			do {
				q[j] = k;
				j = p[j];
				q[k] = j;
				k = p[k];
			} while(j != i);
			cnt[sz] = -1;
		}
	}
	rep(i,0,n+1) if(cnt[i] != -1){
		puts("-1");
		return 0;
	}
	rep(i,0,n) printf("%d ",q[i]+1);
	puts("");
}
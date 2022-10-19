#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,opt,pos[N],k,val;
bool check(int i){
	return i%k == 0;
}
void change(int cnt){
	int x; scanf("%d",&x);
	x--;
	rep(i,x,x+cnt-1){
		pos[i%n] = 0;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,2,n){
		int cur = n-i+1-((n+i-1)/i);
		if(cur > val) val = cur,k = i;
	}
	opt = val;
	// puts("loop");
	while(1){
		int cnt = 0;
		rep(i,1,n) cnt += pos[i];
		if(cnt >= opt){
			printf("0\n");
			fflush(stdout);
			return 0;
		}
		VI cur;
		rep(i,0,n-1) {
			if(check(i) || pos[i]) continue;
			cur.pb(i+1);
		}
		for(auto x:cur) pos[x-1] = 1;
		printf("%d ",SZ(cur));
		for(auto x:cur)
			printf("%d ",x);
		printf("\n"); fflush(stdout);
		change(SZ(cur));
		// rep(i,1,n) printf("%d ",pos[i]);
		// printf("\n");
	}
	return 0;
}
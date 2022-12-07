#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct node{
	int l,r,id;
	bool operator < (const node &b)const
	{
		if(l == b.l) return r < b.r;
		return l < b.l;
	}
};
node a[maxn];
int ans[maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
			a[i].id = i;
		}
		sort(a + 1,a + n + 1);
		ans[a[1].id] = 1;
		int maxr = a[1].r,i;
		for(i=2;i<=n;i++){
			if(a[i].l <= maxr) ans[a[i].id] = ans[a[i - 1].id];
			else break;
			maxr = max(maxr,a[i].r);
		}
		if(i == n + 1) puts("-1");
		else{
			for(;i<=n;i++){
				ans[a[i].id] = 2;
			}
			for(int j=1;j<=n;j++){
				printf("%d%c",ans[j],j == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 0x3f3f3f3f
#define maxc 100005
using namespace std;
typedef long long ll;
int n,m,cl,ce,v,q;
int l[maxc],e[maxc];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=1;i<=cl;i++) scanf("%d",&l[i]);
	for(int i=1;i<=ce;i++) scanf("%d",&e[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int x1,y1,x2,y2,ans = inf;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1 == x2){
			printf("%d\n",abs(y2 - y1));
			continue;
		}
		if(cl != 0){
			if(y1 > l[1]){
			int l1 = upper_bound(l+1,l+cl+1,y1) - l - 1;
			ans = min(ans,abs(l[l1] - y1) + abs(x2 - x1) + abs(l[l1] - y2));
			}
			if(l[cl] > y1){
				int l2 = upper_bound(l+1,l+cl+1,y1) - l;
				ans = min(ans,abs(l[l2] - y1) + abs(x2 - x1) + abs(l[l2] - y2));
			}
		}
		if(ce != 0){
			if(y1 > e[1]){
				int e1 = upper_bound(e+1,e+ce+1,y1) - e - 1;
				ans = min(ans,abs(e[e1] - y1) + (abs(x2 - x1) + v-1) / v + abs(e[e1] - y2));
			}
			if(e[ce] > y1){
				int e2 = upper_bound(e+1,e+ce+1,y1) - e;
				ans = min(ans,abs(e[e2] - y1) + (abs(x2 - x1) + v-1) / v + abs(e[e2] - y2));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
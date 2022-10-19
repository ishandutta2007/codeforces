#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
using namespace std;
int n,a[N],to[N];
bool used[N];
VI one,two,thr;
vector<pii> ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n)
 		scanf("%d",&a[i]);
 	per(i,1,n){
 		if(a[i] == 1) one.pb(i);
 		else if(a[i] == 2){
 			if(one.size() == 0){
 				puts("-1");
 				return 0;
 			}
 			to[i] = one.back(); one.pop_back();
 			two.pb(i);
 		}else if(a[i] == 3){
 			if(thr.size() > 0){
 				to[i] = thr.back(); thr.pop_back();
 			}else if(two.size() > 0){
 				to[i] = two.back(); two.pop_back();
 			}else if(one.size() > 0){
				to[i] = one.back(); one.pop_back();
			}else{
				puts("-1");
				return 0;
			}
 			thr.pb(i);
 		}
 	}
 	int cx = 1,cy = 1;
 	rep(i,1,n){
 		if(used[i] || a[i] == 0) continue;
 		cy = i;
 		while(cy){
 			used[cy] = 1;
 			if(a[cy] == 1){
 				ans.pb(mp(cx,cy));
 				cy = 0;
 				cx++;
 			}else if(a[cy] == 2){
 				ans.pb(mp(cx,cy));
 				cy = to[cy];
 			}else if(a[cy] == 3){
 				ans.pb(mp(cx,cy));
 				cy = to[cy];
 				ans.pb(mp(cx,cy));
 				cx++;
 			}
 		}
 	}
 	printf("%d\n",ans.size());
 	for(auto v:ans){
 		printf("%d %d\n",v.fi,v.se);
 	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define N 114514
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
int n,a[N];
int query(int k){
	int x;
	printf("? %d\n",k);
	fflush(stdout);
	scanf("%d",&x); return x;
}
void get(int k){
	if(!a[k]) a[k] = query(k);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	a[0] = a[n+1] = inf;
 	if(n <= 100){
 		rep(i,1,n) a[i] = query(i);
 		rep(i,1,n) if(a[i]<min(a[i-1],a[i+1])){
 			printf("! %d\n",i);
 			fflush(stdout);
 			return 0;
 		}
 	}
 	get(1);get(2);get(n-1);get(n);
 	if(a[1]<a[2]) {
 		printf("! %d\n",1);
		fflush(stdout);
		return 0;
 	}
 	if(a[n]<a[n-1]){
 		printf("! %d\n",n);
		fflush(stdout);
		return 0;
 	}
 	int l = 1,r = n;
 	while(l+2 < r){
 		int mid = (l+r)>>1;
 		get(mid-1);get(mid);get(mid+1);
 		if(a[mid]<min(a[mid-1],a[mid+1])){
 			printf("! %d\n",mid);
 			fflush(stdout);
 			return 0;
 		}
 		if(a[mid-1]<a[mid]&&a[mid]<a[mid+1]) r = mid;
 		else l = mid;
 	}
 	rep(i,l,r) get(i);
 	rep(i,l,r) if(a[i]<min(a[i-1],a[i+1])){
 		printf("! %d\n",i);
		fflush(stdout);
		return 0;
 	}
	return 0;
}
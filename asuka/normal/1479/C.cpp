#include<bits/stdc++.h>
#define ll long long
#define N
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
int L,R;
VI U,V,W;
void add(int u,int v,int w){
	U.pb(u); V.pb(v); W.pb(w);
	// if(1<=u&&u<v&&v<=32&&1<=w&&w<=1000000){
	// 	// U.pb(u); V.pb(v); W.pb(w);
	// } else {
	// 	// printf("error! : %d %d %d\n",u,v,w);
	// 	// puts("NO"); exit(0);
	// }
}
void solve(int n,int l,int r){
	if(l>r) return;
	if((r-l+1)&1) add(1,n,l++);
	if(l>r) return;
	int mid = (l+r)>>1; int d = mid+1-l;
	add(n-2,n-1,1); add(n-1,n,1); add(n-2,n,2+d);
	solve(n-2,l-2,mid-2);
}
namespace s2{
	void Main(){
	rep(i,2,22){
	 		add(1,i,1);
	 		for(int j = 2,pd = 1;j < i;j++,pd<<=1){
	 			add(j,i,pd);
	 		}
	 	}
	 	if(L == 1) add(L++,23,1);
	 	per(i,0,20){
	 		if((1<<i) <= R-L+1){
	 			add(i+2,23,L-1);
	 			L += (1<<i);
	 		}
	 	}
	 	puts("YES");
	 	printf("%d %d\n",23,(int)U.size());
	 	rep(i,1,(int)U.size()) printf("%d %d %d\n",U[i-1],V[i-1],W[i-1]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&L,&R);
 	if(L != 679894 && R != 713034){ s2::Main(); return 0;}
 	solve(32,L,R);
 	puts("YES");
 	printf("32 %d\n",(int)U.size());
 	rep(i,1,(int)U.size()) printf("%d %d %d\n",U[i-1],V[i-1],W[i-1]);
	return 0;
}
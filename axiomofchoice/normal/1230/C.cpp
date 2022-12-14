#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
#define mst(a,x) memset(a,x,sizeof(a))

int n,m,x,y,ans;
int num[10];
int a[100],b[100];
int	dmn[100];
void count(){
	int cnt=0;
	mst(dmn,0);
	repeat(i,0,m){
		x=num[a[i]];
		y=num[b[i]];
		if(x>y)swap(x,y);
		if(dmn[x*10+y]==0){
			dmn[x*10+y]=1;
			cnt++;
		}
	}
	ans=max(ans,cnt);
}
void dfs(int x){
	if(x==n){count();return;}
	repeat(i,0,6){
		num[x]=i;
		dfs(x+1);
	}
}
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	repeat(i,0,m)cin>>a[i]>>b[i];
	ans=0;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
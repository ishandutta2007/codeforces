#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int M = 30;

int n;
int a[N],b[N],id[N];
bool f[N][M];

bool cmp(int x,int y){
	return b[x]<b[y];
}

bool Solve(int l,int r,int d){
	if(l>r||d==-1)return 1;
	int mid=l-1;
	for(int i=l;i<=r;++i)
	if(!(b[id[i]]&1<<d)){
		mid=i;
	}
	bool f1=1,f2=1;
	for(int i=l;i<=mid;++i)if(!f[i][d])f2=0;
	for(int i=mid+1;i<=r;++i)if(!f[i][d])f1=0;
	bool ret=0;
	if(f1)ret|=Solve(l,mid,d-1);
	if(f2)ret|=Solve(mid+1,r,d-1);
	return ret;
}

bool check(int ans){
	for(int i=1;i<=n;++i){
		b[i]=a[i]^ans;
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=0;j<M;++j)
		if((a[id[i]]^b[id[i]])&1<<j)f[i][j]=1;
		else f[i][j]=0;
	}
	return Solve(1,n,M-1);
} 

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=0,r=(1<<M)-1;
	while(l!=r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
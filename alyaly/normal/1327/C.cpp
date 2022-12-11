#include<bits/stdc++.h>
#define int long long
using namespace std;
struct dot{
	int x,y,gx,gy;
} a[100001];
int n,m,K,ans;
string sans;
signed main(){
	cin>>n>>m>>K;
	for(int i=1;i<=K;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=K;i++){
		cin>>a[i].gx>>a[i].gy;
	}
	for(int i=1;i<n;i++){
		ans++;
		sans+='U';
	}
	for(int i=1;i<m;i++){
		ans++;
		sans+='L';
	}
	for(int i=1;i<=n;i++){
		if(i%2) for(int j=1;j<m;j++){
			ans++;
			sans+='R';
		}else for(int j=1;j<m;j++){
			ans++;
			sans+='L';
		}
		ans++;
		sans+='D';
	}
	cout<<ans<<endl<<sans<<endl;
	return 0;
}
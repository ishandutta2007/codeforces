#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
const int M = 1e3+5;

int n,m,g,r;
int d[N];
int f[N][M];
int q[N*M*2];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>d[i];
	}
	d[++m]=n;
	cin>>r>>g;
	sort(d+1,d+m+1);
	for(int i=m;i>=1;--i)d[i]=d[i]-d[i-1];
	int L=N*M,R=N*M;
	q[N*M]=0;
	f[0][0]=1;
	while(L<=R){
		int x=q[L++];
		int w,i=x/r,val=x%r;
		//cout<<i<<" "<<val<<endl;
		w=val+d[i+1];
		if(i==m)continue;
		if(i!=m&&w<=r){
			if(w==r){
				if(!f[i+1][0]){
					f[i+1][0]=f[i][val]+1;
					q[++R]=(i+1)*r;
				}
			}
			else{
				if(!f[i+1][w]){
					f[i+1][w]=f[i][val];
					q[--L]=(i+1)*r+w;
				}
			}
		}
		w=val+d[i];
		if(i>1&&w<=r){
			if(w==r){
				if(!f[i-1][0]){
					f[i-1][0]=f[i][val]+1;
					q[++R]=(i-1)*r;
				}
			}
			else{
				if(!f[i-1][w]){
					f[i-1][w]=f[i][val];
					q[--L]=(i-1)*r+w;
				}
			}
		}
	}
	ll ans=1e18;
	for(int i=0;i<r;++i)
	if(f[m][i]){
		ans=min(ans,1ll*(f[m][i]-1)*r+1ll*(f[m][i]-1)*g+i+(i==0?-g:0));
	}
	if(ans==1e18)cout<<-1<<endl;
	else cout<<ans<<endl;
}
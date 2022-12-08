#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int n,h,l,r;
int a[N];
int f[N][N];

int main(){
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;++i)cin>>a[i];
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;++i){
		for(int j=0,t;j<h;++j)
		if(f[i][j]>=0){
			t=(j+a[i+1])%h;
			f[i+1][t]=max(f[i+1][t],f[i][j]+(l<=t&&t<=r));
			t=(j+a[i+1]-1)%h;
			f[i+1][t]=max(f[i+1][t],f[i][j]+(l<=t&&t<=r));
		}
	}
	cout<<*max_element(f[n],f[n]+h)<<endl;
}
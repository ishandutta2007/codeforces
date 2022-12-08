#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e7+5;
const int MAX_A = 5e6+5;

int n,a[N];
int c[N];
int f[N];
ll g[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],c[a[i]]++;
	for(int i=1;i<=MAX_A;++i)
	for(int j=1;j*i<=MAX_A;++j){
		f[i]+=c[i*j];
	}
	for(int i=MAX_A;i>=1;--i){
		g[i]=1ll*i*f[i];
		for(int j=2;j*i<=MAX_A;++j){
			g[i]=max(g[i],g[i*j]+1ll*i*(f[i]-f[i*j]));
		}
	}
	cout<<g[1]<<endl;
}
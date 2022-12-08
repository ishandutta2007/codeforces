#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
int a[N],b[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>b[i];
	int x=0;
	for(int i=1;i<=n;++i){
		a[i]=x+b[i];
		x=max(x,a[i]); 
	}
	int res=0;
	for(int i=1;i<=n;++i)
	if(a[i]>1e9){
		res=max(res,a[i]-(int)1e9);
	}
	for(int i=1;i<=n;++i)a[i]-=res;
	res=0;
	for(int i=1;i<=n;++i)
	if(a[i]<0){
		res=max(res,0-a[i]);
	}
	for(int i=1;i<=n;++i)a[i]+=res;
	for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	cout<<endl;
}
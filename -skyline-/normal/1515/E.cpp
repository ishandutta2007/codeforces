#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
using namespace std;
int n;
ll p,f[805][805],ans,b[805],c[805][805];
int main(){
	cin>>n>>p;
	c[0][0]=1;
	for(int i=1;i<=801;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)(c[i][j]=c[i-1][j-1]+c[i-1][j])%=p;
	}
	b[0]=1;
	for(int i=1;i<=801;++i)b[i]=b[i-1]*2%p;f[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=i;++j){
			for(int k=1;i+k<=n;++k)(f[i+k+1][j+k]+=f[i][j]*b[k-1]%p*c[k+j][j]%p)%=p;
		}
	}
	for(int i=1;i<=n;++i)(ans+=f[n+1][i])%=p;
	cout<<(ans%p+p)%p<<endl;
    return 0;
}
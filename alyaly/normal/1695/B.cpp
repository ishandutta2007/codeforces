#include<bits/stdc++.h>
#define int long long
#define N 100
using namespace std;
int T,n,a[N+1],kx,ky,b[2],p[2];
void putin(){
	b[0]=b[1]=999999999999;
	p[0]=p[1]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<b[i%2])p[i%2]=i;
		b[i%2]=min(b[i%2],a[i]);
	}
}
signed main(){
	cin>>T;
	while(T--){
		putin();
		if(n%2)cout<<"Mike"<<endl;
		else cout<<((b[1]>b[0]||b[1]==b[0]&&p[1]>p[0])?"Mike":"Joe")<<endl;
	}
	return 0;
}
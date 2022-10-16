#include<bits/stdc++.h>
using namespace std;
int inf=1e8;
int n,m,a[5005];
signed main(){
	cin>>n;
	cin>>m;
	int cnt=0,num=0;
	for(int i=1;i<=n;i++){
		a[i]=i;
		if(cnt+(i-1>>1)<=m)num++,cnt+=i-1>>1; else break;
	}
//	cout<<cnt<<endl;
	if(m>cnt&&num==n)puts("-1"),exit(0);
	if(m==cnt&&num==n){for(int i=1;i<=n;i++)cout<<a[i]<<" "; exit(0);}
//	cout<<num<<endl;
	int res=m-cnt;
	a[num+1]=2*(num-res)+1;
	int now=a[++num]+1;
	for(int i=1;i<=n;i++){
		if(a[i])cout<<a[i]<<" ";
		else inf+=now,a[i]=inf,cout<<a[i]<<" "; 
	}
	return 0;
}
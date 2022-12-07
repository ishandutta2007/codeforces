#include<bits/stdc++.h>
using namespace std;
long long T,d[200003],n;
bool cmp(long long a,long long b){return a>b;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<2*n;i++)
			scanf("%lld",d+i);
		sort(d,d+n+n,cmp);
		long long cnt=0,lst=2233232323233ll;
		bool flag=1;
		for(int i=0;i<2*n;i+=2){
			if(d[i]!=d[i+1])flag=0;
			long long nwd=d[i]-cnt;
			cnt+=nwd/(2*n-i)*2;
			if(nwd%(2*n-i)||nwd<=0)flag=0;
			if(nwd/(2*n-i)>=lst)flag=0;
			lst=nwd/(2*n-i);
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
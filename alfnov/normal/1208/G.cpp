#include<bits/stdc++.h>
using namespace std;
int s[1000005],d[1000005],e[1000005],tot=0;
int a[1000005];
int main(){
	int n,k;
	cin>>n>>k;
	if(k==1){
		printf("3\n");
		return 0;
	}else if(k==2){
		printf("6\n");
		return 0;
	}
	e[1]=1,s[1]=1;
	for(int i=2;i<=n;++i){
		if(!s[i])d[++tot]=i,e[i]=i-1;
		for(int j=1;j<=tot&&i*d[j]<=n;++j){
			s[i*d[j]]=1;
			if(i%d[j]==0){
				e[i*d[j]]=e[i]*d[j];
				break;
			}
			e[i*d[j]]=e[i]*(d[j]-1);
		}
	}
	sort(e+3,e+n+1);
	long long ans=2;
	for(int i=3;i<=k+2;++i)ans+=e[i];
	cout<<ans<<endl;
	return 0;
}
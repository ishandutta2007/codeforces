#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int b[N];
long long s[N];
map<int,int>mp;
int main(){
	long long ans=0;
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	for(i=1;i<=n;++i){
		if(mp.count(i-b[i])){
			s[mp[i-b[i]]]+=b[i];
		}else mp[i-b[i]]=i,s[i]+=b[i];
	}
	for(i=1;i<=n;++i)ans=max(ans,s[i]);
	printf("%lld",ans);
	return 0;
}//
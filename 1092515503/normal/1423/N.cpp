#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
bool on[12510];
int sum[12510];
int val[1001000],s[1001000],t[1001000];
vector<int>v[12510];
set<int>hs;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&s[i],&t[i]),val[i]=1,sum[s[i]]++,sum[t[i]]++,v[s[i]].push_back(i),v[t[i]].push_back(i);
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			if((s[j]^t[j]^i)>i)continue;
			if(!on[s[j]^t[j]^i])on[s[j]^t[j]^i]=true,val[j]--,sum[i]--;
			hs.insert(sum[s[j]^t[j]^i]); 
		}
		for(auto j:v[i]){
			if((s[j]^t[j]^i)>i)continue;
			if(hs.find(sum[i])==hs.end())break;
			on[s[j]^t[j]^i]=false,val[j]++,sum[i]++;
		}
		hs.clear();
	}
	for(int i=1;i<=n;i++)cnt+=on[i];
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(on[i])printf("%d ",i);if(cnt)puts("");
	for(int i=1;i<=m;i++)printf("%d %d %d\n",s[i],t[i],val[i]);
	return 0;
}
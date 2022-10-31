#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[110],c[2];
	scanf("%d",&n);
	c[0]=n/2;
	c[1]=(n+1)/2;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0) c[a[i]&1]--;
	}
	int pre=-1,ans=0,st;
	vector<int> v[2];
	for(int i=0;i<n;i++){
		if(a[i]>0){
			if(pre==-1) st=i;
			if(pre>=0&&a[i]%2==a[pre]%2){
				v[a[i]%2].push_back(i-pre-1);
			}
			else if(pre>=0&&a[i]%2!=a[pre]%2) ans++;
			pre=i;
		}
	}
	if(pre==-1){
		if(n>1) puts("1");
		else puts("0");
	}else{
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		for(int i=0;i<v[0].size();i++){
			//printf("%d\n",v[0][i]);
			if(c[0]>=v[0][i]) c[0]-=v[0][i];
			else ans+=2;
		}
		for(int i=0;i<v[1].size();i++){
			//printf("%d\n",v[1][i]);
			if(c[1]>=v[1][i]) c[1]-=v[1][i];
			else ans+=2;
		}
		if(c[a[st]&1]>=st) c[a[st]&1]-=st;
		else ans++;
		if(c[a[pre]&1]>=n-1-pre) c[a[pre]&1]-=n-1-pre;
		else ans++;
		printf("%d\n",ans);
	}
	return 0;
}
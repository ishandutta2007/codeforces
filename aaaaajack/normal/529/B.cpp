#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int w[1010],h[1010];
bool cmp(int i,int j){
	return h[i]-w[i]<h[j]-w[j];
}
int main(){
	vector<int> v,u;
	bool flag=false;
	int n,i,j,lie,len,ans=2023456789;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&w[i],&h[i]);
		v.push_back(w[i]);
		v.push_back(h[i]);
	}
	sort(v.begin(),v.end(),greater<int>());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++){

		lie=n/2;
		len=0;
		u.clear();
		for(j=0;j<n;j++){
			if(h[j]>v[i]&&w[j]>v[i]){
				flag=true;
				break;
			}
			if(h[j]>v[i]){
				lie--;
				len+=h[j];
			}
			else if(w[j]>v[i]){
				len+=w[j];
			}
			else if(h[j]>w[j]){
				len+=w[j];
			}
			else{
				u.push_back(j);
			}
		}
		if(flag||lie<0) break;
		sort(u.begin(),u.end(),cmp);
		for(j=0;j<u.size();j++){
			if(j<lie) len+=h[u[j]];
			else len+=w[u[j]];
		}
		ans=min(ans,v[i]*len);
	}
	printf("%d\n",ans);
	return 0;
}
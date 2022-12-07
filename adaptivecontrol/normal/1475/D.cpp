#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[200003],b;
vector<long long>v[2];
long long check(long long x){
	if(v[0].back()<x)return 2333333333333333ll;
	long long l=0,r=v[0].size()-1;
	while(l!=r){
		long long mid=(l+r)/2;
		if(v[0][mid]>=x)
			r=mid;
		else
			l=mid+1;
	}return l;
}
bool cmp(long long a,long long b){return a>b;}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;v[0].clear();v[1].clear();
		for(int i=0;i<n;i++)scanf("%d",a+i);
		long long cnt=0,ans=2333333333333333ll;
		for(int i=0;i<n;i++){
			scanf("%d",&b);
			v[b-1].push_back(a[i]);
			cnt+=a[i];
		}
		if(cnt<m){
			cout<<-1<<endl;
			continue; 
		}v[1].push_back(2333333333333333ll);v[0].push_back(2333333333333333ll);
		sort(v[0].begin(),v[0].end(),cmp);
		sort(v[1].begin(),v[1].end(),cmp);v[0][0]=0;v[1][0]=0;
		for(int i=1;i<v[1].size();i++)v[1][i]+=v[1][i-1];
		for(int i=1;i<v[0].size();i++)v[0][i]+=v[0][i-1];
		for(int i=0;i<v[1].size();i++)
			ans=min(ans,check(m-v[1][i])+i*2);
		cout<<ans<<endl;
	}
}
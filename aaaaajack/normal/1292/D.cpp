#include<bits/stdc++.h>
#define N 5010
#define M 1001000
using namespace std;
int prm[N],cur[N],now[N];
int a[M];
int pcnt=0;
int num[N];
int sz[N];
vector<pair<int,int> > v;
int main(){
	for(int i=2;i<=5000;i++){
		bool flag=false;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				flag=true;
				break;
			}
		}
		if(!flag) prm[pcnt++]=i;
	}
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) a[i]=1;
		num[a[i]]++;
	}
	for(int i=1;i<=5000;i++) cur[i]=i,now[i]=i;
	for(int i=0;i<pcnt;i++){
		memset(sz,0,sizeof(sz));
		for(int j=1;j<=5000;j++){
			while(cur[j]%prm[i]==0) cur[j]/=prm[i];
			while(now[j]>1&&cur[now[j]]==1) now[j]--;
			sz[now[j]]+=num[j];
		}
		int mx=0;
		for(int j=1;j<=5000;j++){
			if(sz[j]>sz[mx]) mx=j;
		}
		v.clear();
		for(int j=1;j<=5000;j++){
			if(!num[j]) continue;
			int val=0;
			int tmp=j;
			while(tmp){
				tmp/=prm[i];
				val+=tmp;
			}
			if(now[j]==mx) v.push_back(make_pair(val,num[j]));
			else v.push_back(make_pair(-val,num[j]));
		}
		sort(v.begin(),v.end());
		int mid,pre=0;
		for(int j=0;j<v.size();j++){
			if(pre>n/2) break;
			pre+=v[j].second;
			mid=v[j].first;
		}
		if(mid<0) mid=0;
		for(int j=0;j<v.size();j++){
			//if(v.front().first<v.back().first) printf("%d: %d %d (mid=%d)\n",prm[i],v[j].first,v[j].second,mid);
			ans+=1LL*abs(mid-v[j].first)*v[j].second;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
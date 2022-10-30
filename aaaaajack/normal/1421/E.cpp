#include<bits/stdc++.h>
#define N 200100
using namespace std;
long long inf=1e18;
int a[N],s[N];
int id[N];
bool cmp(int i,int j){
	if(a[i]>0 && a[j]<=0) return true;
	else if(a[i]<=0 && a[j]>0) return false;
	return a[i]<a[j];
}
long long cal(int n){
	bool flag=(n==1);
	long long res=0;
	int r=0;
	for(int i=0;i<n;i++){
		res+=s[i]*a[i];
		if(i && s[i]==s[i-1]) flag=true;
		r+=s[i]+3;
	}
	if(r%3!=1 || !flag) return -inf;
	return res;
}
int main(){
	int n;
	long long ans=-inf;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0) s[i]=1;
		else s[i]=-1;
		id[i]=i;
	}
	sort(id,id+n,cmp);
	int ed[3],m=min(n-3,3);
	for(int i=0;i<m;i++){
		ed[i]=id[n-1-i];
	}
	for(int i=0;i<m;i++){
		id[3+i]=ed[i];
	}
	m+=3;
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<m;j++){
			if(i&(1<<j)){
				s[id[j]]=-s[id[j]];
			}
		}
		ans=max(ans,cal(n));
		for(int j=0;j<m;j++){
			if(i&(1<<j)){
				s[id[j]]=-s[id[j]];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
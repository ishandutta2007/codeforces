#include<cstdio>
#include<map>
#include<algorithm>
#define N 300100
using namespace std;
int sus[N]={0},temp[N];
int main(){
	int n,p,i,j,x,y,t;
	long long ans=0;
	map<pair<int,int>,int> ovl;
	map<pair<int,int>,int>::iterator it;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		sus[x]++;
		sus[y]++;
		if(x>y) swap(x,y);
		if(ovl.count(make_pair(x,y))) ovl[make_pair(x,y)]++;
		else ovl.insert(make_pair(make_pair(x,y),1));
	}
	for(i=1;i<=n;i++){
		temp[i]=sus[i];
	}
	sort(temp+1,temp+n+1);
	j=1;
	for(i=n;i>=1;i--){
		while(j<=n&&temp[i]+temp[j]<p) j++;
		ans+=(n+1-j);
	}
	for(i=1;i<=n;i++){
		if(2*temp[i]>=p) ans--;
	}
	ans/=2;
	for(it=ovl.begin();it!=ovl.end();it++){
		x=it->first.first,y=it->first.second;
		t=it->second;
		if(sus[x]+sus[y]>=p&&sus[x]+sus[y]-t<p) ans--;
	}
	printf("%I64d\n",ans);
	return 0;
}
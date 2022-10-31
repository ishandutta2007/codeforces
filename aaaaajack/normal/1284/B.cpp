#include<bits/stdc++.h>
#define N 100100
using namespace std;
bool has[N];
int mx[N],mn[N];
int main(){
	int n,t,x,pre;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		pre=1023456789;
		for(int j=0;j<t;j++){
			scanf("%d",&x);
			if(x>pre) has[i]=true;
			pre=x;
			mx[i]=max(mx[i],x);
			mn[i]=x;
		}
	}
	int hs=0;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		if(has[i]) hs++;
		else v.push_back(make_pair(mx[i],mn[i]));
	}
	long long ans=1LL*n*n-1LL*(n-hs)*(n-hs);
	//printf("%lld\n",ans);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		//printf("%d\n",upper_bound(v.begin(),v.end(),make_pair(v[i].second,1023456789))-v.begin());
		ans+=n-hs-(upper_bound(v.begin(),v.end(),make_pair(v[i].second,1023456789))-v.begin());
	}
	printf("%lld\n",ans);
	return 0;
}
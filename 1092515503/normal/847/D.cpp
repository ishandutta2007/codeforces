#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
int n,m,a[200100],res,t[200100],lim;
vector<int>v;
void ADD(int x){while(x<=lim)t[x]++,x+=x&-x;}
int SUM(int x){int sum=0;while(x)sum+=t[x],x-=x&-x;return sum;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i,v.push_back(a[i]);
	sort(v.begin(),v.end()),v.resize(lim=(unique(v.begin(),v.end())-v.begin()));
	for(int i=1;i<=n;i++){
		ADD(lower_bound(v.begin(),v.end(),a[i])-v.begin()+1);
		int rem=m-i-1;
		if(rem>=0)res=max(res,SUM(upper_bound(v.begin(),v.end(),rem)-v.begin()));
	}
	printf("%d\n",res);
	return 0;
}
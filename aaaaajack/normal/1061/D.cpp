#include<bits/stdc++.h>
#define N 300100
using namespace std;
int l[N],r[N];
bool del[N];
int main(){
	int n,x,y;
	const int Q=1e9+7;
	scanf("%d%d%d",&n,&x,&y);
	multiset<int> s;
	for(int i=0;i<n;i++){
		scanf("%d%d",&l[i],&r[i]);
		s.insert(l[i]);
	}
	long long ans=0;
	sort(r,r+n);
	for(int i=n-1;i>=0;i--){
		auto it=s.upper_bound(r[i]);
		if(it!=s.end()&&1LL*y*(*it-r[i])<=x){
			s.erase(it);
		}
		else{
			ans+=1LL*y*r[i]+x;
			ans%=Q;
		}
	}
	for(auto t:s){
		ans-=1LL*y*t;
		ans=(ans%Q+Q)%Q;
	}
	cout<<ans<<endl;
	return 0;
}
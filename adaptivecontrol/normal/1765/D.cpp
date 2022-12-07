#include<bits/stdc++.h>
using namespace std;
int n,m,a;
long long ans=1;
multiset<int>st;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		ans+=a;
		st.insert(a);
	}
	int lst=0;
	while(st.size()){
		auto it=st.upper_bound(m-lst);
		if(it==st.begin())
			lst=0,ans++;
		else{
			it--;
			lst=(*it);
			st.erase(it);
		}
	}cout<<ans;
}
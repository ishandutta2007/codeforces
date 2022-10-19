#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],b[100100];
map<int,pair<int,int> >mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mp.clear();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			if(i&1)mp[b[i]].first++;
			else mp[b[i]].second++;
		}
		for(int i=1;i<=n;i++){
			if(i&1)mp[a[i]].first--;
			else mp[a[i]].second--;
		}
		bool ok=true;
		for(auto i:mp)ok&=(i.second.first==0&&i.second.second==0);
		puts(ok?"YES":"NO");
	}
	return 0;
}
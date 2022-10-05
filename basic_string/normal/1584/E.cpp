#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,int>m1,m2;
enum{N=300009};
ll a1[N],a2[N];
set<pair<ll,int>>st1,st2;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	ll ans=0,s1,s2;
	cin>>T;
	while(T--){
		cin>>n;s1=s2=0;m1=m2={};ans=0;st1=st2={};
		++m1[s1],++m2[s2];
		st1.insert({s1,0});
		st2.insert({s2,0});
		a1[0]=s1;a2[0]=s2;
		for(i=1;i<=n;++i){
			cin>>j;
			if(i&1){
				s1+=j;
				s2-=j;
				ans+=m1[s1];
				while(st1.size()&&st1.rbegin()->first>s1){
					k=st1.rbegin()->second;
					st2.erase({a2[k],k});
					st1.erase(--st1.end());
					--m1[a1[k]],--m2[a2[k]];
				}
			}else{
				s1-=j;
				s2+=j;
				ans+=m2[s2];
				while(st2.size()&&st2.rbegin()->first>s2){
					k=st2.rbegin()->second;
					st1.erase({a1[k],k});
					st2.erase(--st2.end());
					--m1[a1[k]],--m2[a2[k]];
				}
			}
			++m1[s1],++m2[s2];
			st1.insert({s1,i});
			st2.insert({s2,i});
			a1[i]=s1;a2[i]=s2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
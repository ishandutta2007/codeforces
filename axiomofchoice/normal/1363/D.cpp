#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1010; typedef long long ll;
int T,n,k;
vector<int> a[N];
vector<int> q;
int ans[N];
string s;
int query(){
	cout<<"? "<<q.size()<<' ';
	for(auto i:q)cout<<i<<' '; cout<<endl;
	cout.flush();
	int ans; cin>>ans; if(ans==-1)exit(233);
	return ans;
}
void pushquery(int l,int r){
	repeat(i,l,r+1)
	for(auto j:a[i])
		q.push_back(j);
}
void output(){
	cout<<"! ";
	repeat(i,1,k+1)cout<<ans[i]<<' '; cout<<endl;
	cout.flush();
	cin>>s; if(s[0]=='I')exit(234);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		repeat(i,1,k+1){
			int c; cin>>c;
			a[i].clear();
			while(c--){
				int x; cin>>x;
				a[i].push_back(x);
			}
			//sort(a[i].begin(),a[i].end());
			//a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
		}
		int l=1,r=k;
		
		q.clear();
		repeat(i,1,n+1)q.push_back(i);
		int maxx=query();
		fill(ans+1,ans+k+1,maxx);
		
		while(l<r){
			int m=(l+r)/2;
			q.clear(); pushquery(l,m);
			if(query()!=maxx)l=m+1;
			else r=m;
		}
		int t=l;
		
		sort(a[t].begin(),a[t].end());
		q.clear();
		repeat(i,1,n+1){
			if(!binary_search(a[t].begin(),a[t].end(),i))
				q.push_back(i);
		}
		ans[t]=query();
		output();
	}
	return 0;
}
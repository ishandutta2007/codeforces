#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+12,inf=1e9,LOG=18,mod=1e9+7,block=316;
int n,m,x,v;
ll cur=0;
set<int> st[LOG];
void up(int pos,int x){
	// del pos
	ll l,r;
	for(int i=0;i<LOG;i++){
		if( st[i].find(pos) != st[i].end() )
			continue;
		set<int>::iterator it=st[i].lower_bound(pos);
		
		r=*it;
		it--;
		l=*it;
		
		st[i].insert(pos);
		                         
		cur+=(pos-l)*(pos-l+1)/2*(1ll<<i);
		cur+=(r-pos)*(r-pos+1)/2*(1ll<<i);
		cur-=(r-l)*(r-l+1)/2*(1ll<<i);
    }	
    // add pos
    for(int i=0;i<LOG;i++){
		if( ((1<<i)&x) == 0 )
			continue;
		set<int>::iterator it=st[i].find(pos);
		
		it++;
		r=*it;
		it--;
		
		it--;
		l=*it;
		it++;
		
		st[i].erase(pos);
		
		cur-=(pos-l)*(pos-l+1)/2*(1ll<<i);
		cur-=(r-pos)*(r-pos+1)/2*(1ll<<i);
		cur+=(r-l)*(r-l+1)/2*(1ll<<i);
    }	
    
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
 	IOS 
	cin>>n>>m;
	for(int i=0;i<LOG;i++)
		for(int j=0;j<=n+1;j++)
			st[i].insert(j);

	for(int i=1;i<=n;i++){
		cin>>x;
		up(i,x);
	}               
	while(m--){
		cin>>v>>x;
		up(v,x);
		cout<<cur<<endl;
	}
}
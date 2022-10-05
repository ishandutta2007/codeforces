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
int n,x,a[maxn],pos[maxn];
multiset<int> st;
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif               
	cin>>n;    
	for(int i=0;i<n;i++){
		cin>>x;
		pos[x]=i;
	}

	for(int i=0;i<n;i++){
		cin>>a[i];
		st.insert(i-pos[a[i]]);
	}
	for(int i=0;i<n;i++){
		multiset<int>::iterator it=st.lower_bound(i);
		x=1e9;             
		if( it!=st.end() )
			x=min(x,*it-i);
		if( it!=st.begin() ){
			it--;
			x=min(x,i-*it);
		}
		cout<<x<<endl;
		it=st.find(i-pos[a[i]]);
		st.erase(it);
		st.insert(i-pos[a[i]]+n);
	}  
}
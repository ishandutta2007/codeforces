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
const ll maxn=1e6+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=1e6+123;
ll ans,n,k,x,pos[maxn],p[maxn],was[maxn],t[maxn];

int sum (int r){
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}
void inc (int i, int delta){
	for (; i < N; i = (i | (i+1)))
		t[i] += delta;
}
int sum (int l, int r){
	return sum (r) - sum (l-1);
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif                                     
	IOS
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		pos[p[i]]=i;	
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		was[x]=1;
	}
	set<int>st;
	set<int>::iterator it;
	st.insert(0);
	st.insert(n+1);
	for(int i=1;i<=n;i++){
		x=pos[i];
		if( !was[i] ){
			int l,r;
			it=st.lower_bound(x);
			r=*it-1;
			it--;
			l=*it+1;
			if(l<=r)
			ans+=r-l+1-sum(l,r);
		}
		else
			st.insert(x);
	    inc(x,1);
	}
	cout<<ans;
}
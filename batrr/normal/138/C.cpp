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
const ll maxn=1e5+123,inf=101,LOG=18,block=450,mod=1e9+7,N=5e5+12;
int n,m,a[maxn],h[maxn],r[maxn],l[maxn],b[maxn],z[maxn];
double t[4*N+12],ans;
set<int>st;
map<int,int>mt;
void up(int v,int tl, int tr, int l, int r, double val){
	if(l>r)
		return ;
	if( tl==l && tr==r ){
		t[v]*=val;
		return;
	} 
	int tm=(tl+tr)/2;
	up(v+v,tl,tm,l,min(tm,r),val);
	up(v+v+1,tm+1,tr,max(tm+1,l),r,val);
}
double get(int v,int tl, int tr, int pos){
	if(tl==tr)
		return t[v];
	int tm=(tl+tr)/2;
	if( pos<= tm)                      
		return get(v+v,tl,tm,pos)*t[v];
	else
		return get(v+v+1,tm+1,tr,pos)*t[v];
}
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    IOS                          
   	for(int i=0;i<4*N+12;i++)
   		t[i]=1;
   	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]>>h[i]>>l[i]>>r[i];
		st.insert(a[i]-h[i]);
		st.insert(a[i]-1);
    	st.insert(a[i]+1);
    	st.insert(a[i]+h[i]);
    }
    for(int i=0;i<m;i++){
		cin>>b[i]>>z[i];
		st.insert(b[i]);
	}
	while(!st.empty()){
		mt[*st.begin()]=mt.size()+1;
		st.erase(st.begin());
	}                
	for(int i=0;i<n;i++){                 
		up(1,1,N,mt[a[i]-h[i]],mt[a[i]-1],1.0*(100-l[i])/100);
		up(1,1,N,mt[a[i]+1],mt[a[i]+h[i]],1.0*(100-r[i])/100);
	//	cout<<mt[a[i]-h[i]]<<" "<<mt[a[i]-1]<<" "<<mt[a[i]+1]<<" "<<mt[a[i]+h[i]]<<endl;	
	}
	for(int i=0;i<m;i++)
		ans+=z[i]*get(1,1,N,mt[b[i]]);
	cout<<fixed<<setprecision(20)<<ans;	
}
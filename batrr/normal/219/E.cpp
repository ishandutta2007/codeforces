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
const ll maxn=2e5+123,inf=101,LOG=18,block=450,mod=1e9+7,N=1e6+12;
int n,q,pos[N];
set< pair < int , int > > star;//array  mp(l-r,st)
set< int > st;// cars pos
int get(int x){
	int res=1e9;
	set<int>::iterator it;
	it=st.lower_bound(x);       
	if( *it != n+1 )
		res=min(res,abs(*it-x));
	it--;
	if( *it != 0 )
		res=min(res,abs(*it-x));
	return res;
}
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    IOS                          
	cin>>n>>q;      
	star.insert(mp(-(n+1)/2,0));
	st.insert(0);
	st.insert(n+1);
	while(q--){
		int type,id,l,r,x;
		set<int>::iterator it;
		cin>>type>>id;
		if(type==1){
			x=1;	
			//cout<<(*star.begin()).s<<" "<<(*star.begin()).f<<endl;
			if( get(x) < get((*star.begin()).s-(*star.begin()).f) )
				x=(*star.begin()).s-(*star.begin()).f;
			if( get(x) < get(n) )
				x=n;
			
			pos[id]=x;
			it=st.lower_bound(pos[id]);
			r=*it;
			it--;
			l=*it;	                          
			//cout<<l<<" "<<r<<endl;
			star.erase(mp( (l-r)/2 ,l));
	    	star.insert(mp( (pos[id]-r)/2 ,pos[id]));
			star.insert(mp( (l-pos[id])/2 ,l));
			st.insert(pos[id]);
			cout<<pos[id]<<endl;
		
		}else{
			st.erase(pos[id]);
			it=st.lower_bound(pos[id]);
			r=*it;
			it--;
			l=*it;	                          
			star.erase(mp( (pos[id]-r)/2 ,pos[id]));
			star.erase(mp( (l-pos[id])/2 ,l));
			star.insert(mp( (l-r)/2 ,l));
	
		}
	}   		
}
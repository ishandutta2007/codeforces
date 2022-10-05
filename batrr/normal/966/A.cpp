#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                   
#define ld long double                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,MX=1e9,inf=1e9,block=2;
int n,m,A,B,v,q,x;
set<int>sta,stb;
int xa,ya,xb,yb,ans;
int geta(){
	if(A==0)
		return 1e9;
	int res=1e9;
	set<int>::iterator it=sta.lower_bound( min(ya,yb) );
	if(it!=sta.end())
		res=min(res, abs(ya-*it)+abs(yb-*it) ); 
	if(it!=sta.begin()){
		it--;
		res=min(res, abs(ya-*it)+abs(yb-*it) ); 
	}
	return res+abs(xa-xb);	
}      

int getb(){                 
	if(B==0)
		return 1e9;
	int res=1e9;
	set<int>::iterator it=stb.lower_bound( min(ya,yb) );
	if(it!=stb.end())
		res=min(res, abs(ya-*it)+abs(yb-*it) ); 
	if(it!=stb.begin()){
		it--;
		res=min(res, abs(ya-*it)+abs(yb-*it) ); 
	}
	return res+(abs(xa-xb)+v-1)/v;	
}      
int main(){             
	scanf("%d%d",&n,&m);  
	scanf("%d%d",&A,&B);
	scanf("%d",&v);      
	for(int i=1;i<=A;i++){
		scanf("%d",&x);
		sta.insert(x);
	}
	for(int i=1;i<=B;i++){
		scanf("%d",&x);
		stb.insert(x);
	}
	scanf("%d",&q);      
	while(q--){
		scanf("%d%d",&xa,&ya);
		scanf("%d%d",&xb,&yb);
		if(xa==xb)
			ans=abs(ya-yb);        
		else
			ans=min( geta() , getb() );
		printf("%d\n",ans);
	}

}
#include <bits/stdc++.h>
 
#define nm "" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,mod=1e9+7,N=2e6+123;
ll n,m,v,u,w,ans;
map< int , int > mt[maxn];
set<int>st[maxn];
int main(){               
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mt[i][-1]=0;;
		mt[i][1e9]=1e9;  
		st[i].insert(-1);
		st[i].insert(1e9);
	}
	for(int i=1;i<=m;i++){
		cin>>v>>u>>w;                    
		map< int , int > :: iterator mit;
		set< int  > :: iterator sit;
		sit=st[v].lower_bound(w);
		if( *sit== w)
			continue;
		sit--;
		ll d=mt[v][*sit]+1;
		while(true){
			sit=st[u].lower_bound(w);
			if( mt[u][*sit] <= d ){
				mt[u].erase(*sit);
				st[u].erase(*sit);
            }else{
            	if(*sit==w)
            		break;
            	sit--;
            	if(mt[u][*sit]<=d){
            		mt[u][w]=d;
            		st[u].insert(w);
            	}
            	break;
            }
        } 
        ans=max(ans,d);
	}
	cout<<ans;
}
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
const ll maxn=3e5+123,inf=1e18,LOG=18,block=450;
ll n,m,was[maxn][2],p[maxn];
int main(){
    #ifdef LOCAL                         
		freopen ("test.in", "r", stdin);
    #endif
    IOS                                  
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int v,u;
    	cin>>v>>u;
    	if(was[v][0])
    		was[v][1]=u; 
    	else
    		was[v][0]=u;
    	if(was[u][0])
    		was[u][1]=v; 
    	else
    		was[u][0]=v;
    }
    ll abdu=100,cur;
    for(int i=1;i<=n;i++)
    	p[i]=i;
    while(abdu--){          
   		random_shuffle(p+1,p+1+n);
   		p[n+1]=p[1];	 
   		cur=0;
   		for(int i=1;cur<m && i<=n;i++)
   			if( was[p[i]][0]!=p[i+1] && was[p[i]][1]!=p[i+1] )
   				cur++;
   		if( cur==m ){
   			cur=0;
   			for(int i=1;cur<m && i<=n;i++)
   				if( was[p[i]][0]!=p[i+1] && was[p[i]][1]!=p[i+1] )
   					cur++,cout<<p[i]<<" "<<p[i+1]<<endl;
   			return 0;
   		}
    }
    cout<<-1;
}
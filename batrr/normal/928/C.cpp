#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
  
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
  
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>                                              
  
#include <ctime>
#include <cassert> 
  
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double                                                                                                              
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
 
using namespace std;                    
const ll maxn=1e6+123,N=2e5,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
map< pair < string ,int > , int > mt1; // name,ver=id
map< int , pair < string ,int > > mt2;
map< string , int > ans,dis,was; 
vector< int > gr[maxn];
int n,cnt,x,m; 
bool used[maxn];
string s,t;
int get( string s, int ver){
	if(mt1[mp(s,ver)] == 0){
		cnt++;
		mt1[mp(s,ver)]=cnt;
		mt2[cnt]=mp(s,ver);
	}
	return mt1[mp(s,ver)];
}
int main(){ 
	//IO
	cin>>n;
	for(int i=1;i<=n;i++){
		//cout<<i<<" ";
		cin>>s>>x;
		int v=get(s,x);		
		
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>s>>x;
	    	int to=get(s,x);	
			gr[v].pb(to);	
		}
		
		//cin>>s;
	}

	queue < pair < int , int > > q;
	q.push(mp(1,0));
	s=mt2[1].f;
	x=mt2[1].s;
	
	was[s]=1;
	dis[s]=0;
	ans[s]=x;

	used[1]=1;

	while( !q.empty() ){
		int v=q.front().f,curdis=q.front().s+1;
		q.pop();
		//cout<<mt2[v].f<<" "<<mt2[v].s<<" - "<<ans[ mt2[v].f ] <<" "<<mt2[v].s<<endl;;
			
		if( ans[ mt2[v].f ] != mt2[ v ].s)
			continue;
		//cout<<"OK"<<endl;
		
		for(int i=0;i<gr[v].size();i++){
			int to=gr[v][i];
			s=mt2[to].f;
			x=mt2[to].s;
			
			//cout<<mt2[v].f<<" "<<mt2[v].s<<" - ";
			
			//cout<<s<<" "<<x<<endl;
			
			if( was[s]==1){
				if( dis[s]<curdis )
					continue;
				
				if( ans[s]>x)
					continue;
			}
			was[s]=1;
			dis[s]=curdis;
			ans[s]=x;
  		    
  		    if( !used[to] ){
				used[to]=1;
				q.push( mp(to,curdis) );
			}
			
			
  		}
	}
	
	s=mt2[1].f;
	ans.erase(s);
    
    cout<<ans.size()<<endl;
	
	for( map < string , int > :: iterator it=ans.begin();it!=ans.end() ;it++ )
		cout<<(*it).f<<" "<<(*it).s<<endl; 
}
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
int n,m,k,x[maxn],was[maxn],used[500][500];
vector< pair<int,int> > ans;
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	cin>>n>>m>>k;
	if(k==n)	
		return cout<<-1,0;
	for(int i=1;i<=k;i++){
		cin>>x[i];        
		was[x[i]]=1;
	}          
	int a=x[1],b=x[2],c;
	for(int i=1;i<=n;i++)
		if( !was[i] )
			c=i;
	for(int i=1;i<=n;i++)
		used[i][i]=1;
    for(int i=1;i<=n;i++)
    	if( m && !used[i][c]){
    		m--;
			used[i][c]=1;
			used[c][i]=1;
			ans.pb(mp(i,c));
		}
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if( i!=b && j!=b){
				if(!used[i][j] && m){
					m--;
					used[i][j]=1;
					used[j][i]=1;
					ans.pb(mp(i,j));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!used[i][b] && !was[i] && m){
			m--;
			used[i][b]=1;
			used[b][i]=1;
			ans.pb(mp(i,b));
		}
	}
	if(m!=0)
		return cout<<-1,0;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].f<<" "<<ans[i].s<<endl;
}
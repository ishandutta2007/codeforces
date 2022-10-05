#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+12,inf=1e9,LOG=18,N=10;
int mod[N],a[maxn][N],b[maxn][N];
int n,m,u[maxn],v[maxn];
ll ans;
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif   
 	
	IOS
	cin>>n>>m;
	srand(time(0));
	for(int j=0;j<N;j++){
		mod[j]=rand()%(int)5e8+5e8;
		for(int i=1;i<=n;i++){
			b[i][j]=rand()%(int)1e9 % mod[j];
		}
	}

	for(int i=1;i<=m;i++){
		cin>>v[i]>>u[i]; 
		for(int j=0;j<N;j++){                                           
			a[v[i]][j]= ( a[v[i]][j] + b[ u[i] ][ j ] )%mod[j]; 
			a[u[i]][j]= ( a[u[i]][j] + b[ v[i] ][ j ] )%mod[j];
		}
	}
	map< vector<int> , ll > cnt;
	for(int i=1;i<=n;i++){
		vector< int > cur; 
		for(int j=0;j<N;j++)
			cur.pb(a[i][j]);
		ans+=cnt[cur];
		cnt[cur]++;		
	}

	for(int i=1;i<=m;i++){
	    bool res=1;
	    for(int j=0;j<N;j++)                                           
			if( ( a[v[i]][j] - b[ u[i] ][ j ] + mod[j])%mod[j] != ( a[u[i]][j] - b[ v[i] ][ j ] + mod[j])%mod[j] )
				res=0;
		ans+=res;
	}
	cout<<ans;
}
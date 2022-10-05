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
const ll maxn=1e6+12,inf=1e9,mod=1e9+7,LOG=18;
int n,a,b,dp[maxn],x[maxn],mx[maxn];
deque < pair< int , int > > dq;
map<int,int>was;
int main() {
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=n;i++){
		if(was[x[i]])
			continue;
 		was[x[i]]=1;
 		int cur=b/x[i]*x[i];
 		while(cur<=a){
 			if(cur>=b)
 				mx[cur-b]=max(mx[cur-b],x[i]);
 			cur+=x[i];
 		}
	}
	
	dq.push_back(mp(0,0));
	for(int i=0;i<=a-b;i++){
		mx[i]=max(mx[i]-1,1);
		dp[i]=dq.front().s;
		
		while( dq.back().s > dp[i]+1 )
			dq.pop_back();
		
		if( dq.back().f < i+mx[i] )	
			dq.push_back(mp(i+mx[i],dp[i]+1));

		while( dq.front().f==i )
			dq.pop_front();
	}
    printf("%d",dp[a-b]);
}
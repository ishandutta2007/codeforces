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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1.1e6+123,inf=1e9,N=5032107+123,mod=1e9+7;
int n,nq,a[maxn],dp[100],last[N][10],ans[maxn];
pair< pair<int,int> ,int > q[maxn];
int main(){
    scanf("%d%d",&n,&nq);
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
    for(int i=0;i<nq;i++){
    	scanf("%d%d",&q[i].f.s,&q[i].f.f);
        q[i].f.f--;
        q[i].f.s--;
        q[i].s=i;
    }
    for(int i=0;i<N;i++)
    	for(int j=0;j<10;j++)
    		last[i][j]=-1;
	for(int i=0;i<100;i++)
    	dp[i]=-1;
    sort(q,q+nq);
    for(int i=0,iq=0;i<n;i++){     
    	int x=a[i];
    	vector<int>p;
        for(int j=2;j*j<=x;j++){
    		while(x%(j*j)==0)
    			x/=j*j;
    		if(x%j==0){
    			x/=j;
    			p.pb(j);
    		}
    	}
    	if(x!=1)
    		p.pb(x);
    	int m=p.size();
    	for(int mask=0;mask<(1<<m);mask++){
    		int cur=1,cnt=0;
    		for(int j=0;j<m;j++)
    			if( (mask&(1<<j)) )
    				cur*=p[j];
    		   	else
    		   		cnt++;
    		for(int j=0;j<10;j++){
    			int w=j+cnt;
    			dp[w]=max(dp[w],last[cur][j]);		
    		}
    		last[cur][cnt]=i;
        }

    	while(iq<nq && q[iq].f.f==i ){
    		int l=q[iq].f.s;
    		for(int j=0;j<20;j++)
    			if( l<=dp[j] ){
    				ans[ q[iq].s ]=j; 
    				break;
    			}
			iq++;
        }
    }

    for(int i=0;i<nq;i++)
    	printf("%d\n",ans[i]);
    return 0;
}
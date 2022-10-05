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

const int maxn=1e5+123,inf=1e9,mod=1e9+7;
int q,n,lst[maxn][30],nxt[maxn][30],dp[maxn];
vector< int > ans1[maxn], ans2[maxn];
char s[maxn];
inline int get(int l,int r, bool flag=0){
	if( l>r )
		return -1;        
	if( r-l<ans1[l].size() && ans1[l][r-l]!=-1 )
		return ans1[l][r-l];
    if( r-l<ans2[r].size() && ans2[r][r-l]!=-1 )
		return ans2[r][r-l];
    
    vector< bool > was(30,0);
    for(int c='a';c<='z';c++){
		int lc=nxt[l][c-'a'];
		int rc=lst[r][c-'a'];
		if( lc>rc )
			continue;
	   	int x = 0;    
	   	if( dp[lc]!=-1 )
	   		x^=dp[lc];
		if( dp[rc]!=-1 )
	   		x^=dp[rc];                        
		if(	get(l,lc-1)!=-1 )
	   		x^=get(l,lc-1);
		if(	get(rc+1,r)!=-1 )
	   		x^=get(rc+1,r);
		was[x]=1;
	}
	for(int i=0;;i++)
		if( was[i]==0 ){
			bool ok=0;
			if( r-l<ans1[l].size() )
				ok=1,ans1[l][r-l]=i;
            if( r-l<ans2[r].size() )
				ok=1,ans2[r][r-l]=i;
            if( !flag && !ok ){
            	cerr<<l<<" "<<r<<endl;
            	assert(0);
            }
            return i;
		}
}
int main(){
	scanf("%s",&s);
    scanf("%d",&q);
    n=(int)strlen(s);
    for(int c='a';c<='z';c++){
        for(int i=0,j=-1e9;i<n;i++){
    		if(s[i]==c)
    			j=i;
    		lst[i][c-'a']=j;
    	}
        for(int i=n-1,j=1e9;i>=0;i--){
    		if(s[i]==c)
    			j=i;   
    		nxt[i][c-'a']=j;
    	}
    }
	for(int i=0;i<n;i++){
		if( i+1<n )
    		ans1[i+1].resize( min(n,nxt[i+1][s[i]-'a']) - i + 10 , -1);
    	if( i>0 )
    		ans2[i-1].resize( i - max(0,lst[i-1][s[i]-'a']) + 10 , -1);
	}
	for(int i=0;i<n;i++){
    	int j;
    	if(i>0)
    		j=lst[i-1][s[i]-'a'];
    	else
    		j=-1e9;
    	
    	if(j!=-1e9){
    		if( get(j+1,i-1)!=-1 )
           		dp[i] = dp[j]^get(j+1,i-1);
    		else
    			dp[i] = dp[j];
    	}else{
    		if( get(0,i-1)!=-1 )
    			dp[i] = get(0,i-1);
    		else
    			dp[i] = 0;
    	}
    }
    while(q--){
    	int l,r;
    	scanf("%d%d",&l,&r);
    	--l,--r;
    	if( get(l,r,1) )    
    		puts("Alice");
    	else
    		puts("Bob");			
    }
    return 0;
}
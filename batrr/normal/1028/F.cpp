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

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,cnt;
map< ll, vector< pair<int,int> > > v;
map< pair<int,int> ,int > ans,ans2;
pair<int,int> get(int x,int y){
	return mp(x/__gcd(x,y),y/__gcd(x,y));
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	int type,x,y;
    	scanf("%d%d%d",&type,&x,&y);
   		if( type==1 ){
   			ll d=1ll*x*x+1ll*y*y;
   			for(int i=0;i<v[d].size();i++)	
   				ans[get(v[d][i].f+x,v[d][i].s+y)]++;
   			v[d].pb({x,y});
   			ans2[get(x,y)]++;
   			cnt++;
   		}
        if( type==2 ){
   			ll d=1ll*x*x+1ll*y*y;                 
   			for(int i=0;i+1<v[d].size();i++){
   				if( v[d][i]==mp(x,y) )
   					swap(v[d][i],v[d][v[d].size()-1]);
   	   			ans[get(v[d][i].f+x,v[d][i].s+y)]--;
   			}
   			v[d].pop_back();
   			ans2[get(x,y)]--;
   			cnt--;
   		}
		if( type==3 )
   			printf("%d\n",cnt-ans2[get(x,y)]-2*ans[get(x,y)]);
    }
    return 0;
}
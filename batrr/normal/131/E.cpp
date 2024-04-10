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
const ll maxn=3e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
int n,m,x[maxn],y[maxn],cnt[maxn];
set<int> st[maxn];
void clean(){
	for(int i=0;i<maxn;i++)
		st[i].clear();
}
int main(){
	//stdi    
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i];       
	
	// rows ->
	for(int i=1;i<=m;i++)
		st[x[i]].insert(y[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]].upper_bound(y[i])!=st[x[i]].end())
   			cnt[i]++;
   	clean();
    // rows <-
	for(int i=1;i<=m;i++)
		st[x[i]].insert(-y[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]].upper_bound(-y[i])!=st[x[i]].end())
   			cnt[i]++;
   	clean();
   	// col down
	for(int i=1;i<=m;i++)
		st[y[i]].insert(x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[y[i]].upper_bound(x[i])!=st[y[i]].end())
   			cnt[i]++;
   	clean();
    // col up
	for(int i=1;i<=m;i++)
		st[y[i]].insert(-x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[y[i]].upper_bound(-x[i])!=st[y[i]].end())
   			cnt[i]++;
   	clean();

   	// di 
   	
   	for(int i=1;i<=m;i++)
		st[x[i]+y[i]].insert(-x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]+y[i]].upper_bound(-x[i])!=st[x[i]+y[i]].end())
   			cnt[i]++;
   	clean();

	for(int i=1;i<=m;i++)
		st[x[i]+y[i]].insert(x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]+y[i]].upper_bound(x[i])!=st[x[i]+y[i]].end())
   			cnt[i]++;
   	clean();

   	// di /


   	for(int i=1;i<=m;i++)
		st[x[i]-y[i]+n].insert(-x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]-y[i]+n].upper_bound(-x[i])!=st[x[i]-y[i]+n].end())
   			cnt[i]++;
   	clean();

	for(int i=1;i<=m;i++)
		st[x[i]-y[i]+n].insert(x[i]);
   	for(int i=1;i<=m;i++)
   		if(st[x[i]-y[i]+n].upper_bound(x[i])!=st[x[i]-y[i]+n].end())
   			cnt[i]++;
   	clean();

   	for(int i=0;i<=8;i++){
   		int ans=0;
   		for(int j=1;j<=m;j++)
   			ans+= ( cnt[j] == i);
   		cout<<ans<<" ";
   	}
}
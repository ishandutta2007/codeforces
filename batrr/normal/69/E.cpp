#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,k,a[maxn];
map<int,int>cnt;
set<int>st;
void add(int x){
	cnt[x]++;
	if(cnt[x]==2)
		st.erase(x);
	if(cnt[x]==1)
		st.insert(x);
}
void del(int x){
	cnt[x]--;
	if(cnt[x]==0)
		st.erase(x);
	if(cnt[x]==1)
		st.insert(x);
}
int main(){              
	cin>>n>>k;         
	
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<k;i++)
		add(a[i]);
   	for(int i=k;i<=n;i++){
    	add(a[i]);
    	if(st.empty())
    		cout<<"Nothing"<<endl;
    	else
    		cout<<*st.rbegin()<<endl;
    	del(a[i-k+1]);
   	}
}
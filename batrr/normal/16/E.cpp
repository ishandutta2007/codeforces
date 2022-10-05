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
const ll maxn=1e6+132,mod=1e9+7;       
int n;
ld c[20][20],ans[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	
		for(int j=0;j<n;j++)
			cin>>c[i][j];
	ans[ (1<<n )-1 ]=1;
	for(int x=(1<<n )-1;x>=0;x--){
		vector<int>v;
		for(int i=0;i<n;i++)
			if( (1<<i) & x)
				v.pb(i);
		ld k=v.size()*(v.size()-1)/2.0;
		k=1.0/k;
		bitset<5>b=x;
		//cout<<b<<" "<<ans[x]<<endl;
		//cout<<v.size()<<" "<<k<<endl;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<i;j++){
				int a=v[i],b=v[j];                
				ans[ x ^ ( 1 << a ) ] += c[b][a]*k*ans[x];
				ans[ x ^ ( 1 << b ) ] += c[a][b]*k*ans[x];
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<fixed<<setprecision(20)<<ans[ (1<<i) ]<<" ";
}
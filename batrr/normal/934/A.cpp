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
const ll maxn=1e5+123,inf=1e9,INF=1e18,N=1e6;
using namespace std;
ll n,m,a[maxn],b[maxn],ans=INF;
int main(){
	//IO
	cin>>n>>m;    
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int q=1;q<=n;q++){
		ll res=-INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i!=q){
					res=max(res,a[i]*b[j]);
				}
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
}
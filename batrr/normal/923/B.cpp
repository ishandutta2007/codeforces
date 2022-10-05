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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=2e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,a[maxn],b[maxn],pre[maxn],ans[maxn],up[maxn];
ll get(int l, int r){
	return pre[r]-pre[l-1];
}
int main(){
	cin>>n;              
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		pre[i]=pre[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int m=(l+r)/2;
			if(get(i,m)<a[i])
				l=m+1;
			else
				r=m-1;		
		}
		up[i]++;
		up[l]--;
		ans[l]+=a[i]-get(i,l-1);
	}		
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=up[i];
		cout<<ans[i]+cnt*b[i]<<" ";
	}
}
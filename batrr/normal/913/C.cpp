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
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
using namespace std;
const int maxn=1e6+1,mod=1e9+7,M=3600*12;
const ll inf=1e18;
const ld eps=1e-6;
ll n,p2[35],a[35],l,ans=inf;
int main(){   
	a[0]=inf;
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>a[i];     
		a[i]=min(a[i],a[i-1]*2);
		p2[i]=p2[i-1]*2;
		p2[1]=1;
		if(p2[i]>=l)
			ans=min(ans,a[i]);
	}
	ll cur=0;
	for(int i=n;i>=1;i--){
		cur+=a[i]*(l/p2[i]);
		if(l%p2[i]==0)
			ans=min(cur,ans);
		ans=min(cur+a[i],ans);
		//cout<<i<<" "<<ans<<endl;
		l%=p2[i];
	}
	cout<<ans;
	return 0; 
}
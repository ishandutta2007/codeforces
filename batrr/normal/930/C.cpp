#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring> 
#include <string> 
#include <string.h>
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
const ll maxn=2e5+123,N=2e5,inf=1e9,mod=1e9+7,INF=1e18;
const ld eps=1e-12,PI=3.141592653589793238462643383279;  
int n,m,upd[maxn],a[maxn],d1[maxn],d2[maxn];
int t[4*maxn];
void up(int v, int tl, int tr , int pos ,int val){
	if(tl==tr){
		t[v]=max(t[v],val);
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)	               
		up(v+v,tl,tm,pos,val);
	else
		up(v+v+1,tm+1,tr,pos,val);
	t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v ,int tl, int tr , int l, int r){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return t[v];
	int tm=(tl+tr)/2;
	return max(
	get(v+v,tl,tm,l,min(tm,r)),
	get(v+v+1,tm+1,tr,max(tm+1,l),r)
	);
}
void print(){
	for(int i=1;i<=m;i++)
		cout<<a[i]<<" ";
	o
	for(int i=1;i<=m;i++)
		cout<<d1[i]<<" ";
	o

	for(int i=1;i<=m;i++)
		cout<<d2[i]<<" ";
}
void scan(){cin>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	}
int main(){                                         
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		upd[l]++;
		upd[r+1]--;
	}
	for(int i=1;i<=m;i++)
		a[i]=a[i-1]+upd[i];
	for(int i=1;i<=m;i++)
		a[i]++;

	for(int i=1;i<=m;i++){
		d1[i]=1+get(1,1,N,1,a[i]);
		up(1,1,N,a[i],d1[i]);
	}
	
	for(int i=0;i<4*maxn;i++)               	
		t[i]=0;
	
	for(int i=m;i>=1;i--){
		d2[i]=1+get(1,1,N,1,a[i]);	
		up(1,1,N,a[i],d2[i]);
	}
    
    //print();

    int ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans,d1[i]+d2[i]-1);
	cout<<ans;
}
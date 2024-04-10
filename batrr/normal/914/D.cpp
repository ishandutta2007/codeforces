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
const ll maxn=5e5+123,inf=2e9,mod=1e9+7; 
int t[4*maxn];
int n,x,l,r,ty,q,ans;
void up(int v, int tl, int tr , int pos , int x){
	if(tl==tr){
		t[v]=x;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)
		up(v+v,tl,tm,pos,x);
	else
		up(v+v+1,tm+1,tr,pos,x);
	t[v]=__gcd(t[v+v],t[v+v+1]);	
}
void can(int v, int tl,int tr , int l , int r,int val){
	//cout<<l<<" "<<r<<" "<<ans<<endl;
	if(l>r)
		return ;
	if(t[v]%val==0)
		return;
	if(tl==tr){
		ans++;
		return;
	}
	int tm=(tl+tr)/2;
	if(tl==l && tr==r){
		if(t[v+v]%val!=0 && t[v+v+1]%val!=0){
			ans=2;
			return;
		}
		can(v+v+1,tm+1,tr,tm+1,r,val);
		can(v+v,tl,tm,l,tm,val);
		return ;
	}
	can(v+v,tl,tm,l,min(tm,r),val);
	if(ans<2)
		can(v+v+1,tm+1,tr,max(tm+1,l),r,val);
	return;
}
int main(){
	//IO
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		up(1,1,n,i,x);
	}
	cin>>q;
	while(q--){
		scanf("%d",&ty);
		if(ty==1){                   
			scanf("%d%d%d",&l,&r,&x);
			ans=0;
			can(1,1,n,l,r,x);
			if(ans<=1)
				puts("YES");
			else
				puts("NO");
		}else{
			cin>>l>>x;
			up(1,1,n,l,x);
		}

	}                                           

}
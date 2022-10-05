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
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
pair <int , int > ans[21],t[4*maxn][21];
int add[4*maxn];
int n,q,a[maxn];
void build(int v, int tl, int tr){
	if(tl==tr){
		for(int j=0;j<=20;j++)
			if(  ( ( 1 << j ) & a[tl] ) )
				t[v][j].f++;
			else
				t[v][j].s++;
		return;
	}
	int tm=(tl+tr)/2;
	build(v+v,tl,tm);
	build(v+v+1,tm+1,tr);
	
	for(int j=0;j<=20;j++)         
		t[v][j].f=t[v+v][j].f+t[v+v+1][j].f,
		t[v][j].s=t[v+v][j].s+t[v+v+1][j].s;

}
void push(int v){
	for(int j=0;j<=20;j++){
		if(  ( ( 1 << j ) & add[v] ) ){
			swap(t[v+v][j].f,t[v+v][j].s);
			swap(t[v+v+1][j].f,t[v+v+1][j].s);
		}
	}
	add[v+v]^=add[v];
	add[v+v+1]^=add[v];
	add[v]=0;
}

void up(int v, int tl, int tr , int l ,int r, int x){
	if(l>r)
		return;
	if(tl==l && tr==r){
		add[v]^=x;
		for(int j=0;j<=20;j++)
			if(  ( ( 1 << j ) & x ) )
				swap(t[v][j].f,t[v][j].s);
		
		return ;
	}
	push(v);
	
	int tm=(tl+tr)/2;           
	up(v+v  ,tl,tm  ,l         ,min(tm,r),x);
	up(v+v+1,tm+1,tr,max(tm+1,l),r       ,x);

	for(int j=0;j<=20;j++)         
		t[v][j].f=t[v+v][j].f+t[v+v+1][j].f,
		t[v][j].s=t[v+v][j].s+t[v+v+1][j].s;

}

ll get(int v, int tl, int tr, int l, int r ){
	if(l>r)
		return 0;
	if(tl==l && tr==r){
		ll res=0;
		for(int j=0;j<=20;j++)
			res+= (1ll<<j) * t[v][j].f;
		return res;
	}
	push(v);
	
	int tm=(tl+tr)/2;           
	return 
	get(v+v  ,tl,tm  ,l         ,min(tm,r))
	+
	get(v+v+1,tm+1,tr,max(tm+1,l),r       );

}
int main(){           
	Bystro
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);		
	cin>>q;
	while(q--){
		int type,l,r,x;
		cin>>type;
		if(type==1){
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<endl;
		
		}else{
			cin>>l>>r>>x;
			up(1,1,n,l,r,x);
		}
	}
}
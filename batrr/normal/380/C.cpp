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
const ll maxn=1e6+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
string s;
struct br{
	int l,r,m;
};
br t[4*maxn];
void build(int v, int tl, int tr){
	t[v].l=0;
    t[v].m=0;
    t[v].r=0;
    
    if(tl==tr){
		if(s[tl]=='(')
			t[v].l++;	
		else
			t[v].r++;
		return;
	}
	int tm=(tl+tr)/2;   
	
	build(v+v,tl,tm);
	build(v+v+1,tm+1,tr);
    
    int val=min(t[v+v].l,t[v+v+1].r);                
	
	t[v].l=t[v+v].l+t[v+v+1].l-val;
	t[v].m=t[v+v].m+t[v+v+1].m+val;
	t[v].r=t[v+v].r+t[v+v+1].r-val;
}
br get(int v, int tl, int tr , int l, int r){
	br res,a,b;
	res.l = res.r = res.m= 0;
	if(l>r)
		return res;
	if(tl==l && tr==r)
		return t[v];
	int tm=(tl+tr)/2;            

	a=get(v+v,tl,tm,l,min(tm,r));
	b=get(v+v+1,tm+1,tr,max(tm+1,l),r);

	int val=min(a.l,b.r);                
	
	res.l=a.l+b.l-val;
	res.m=a.m+b.m+val;
	res.r=a.r+b.r-val;

	return res;
}
int q,n,l,r;
int main(){           
	
	cin>>s;
	n=s.size();
	s='#'+s;
	
	build(1,1,n);
	
	cin>>q;
	while(cin>>l>>r)
		cout<<2*get(1,1,n,l,r).m<<endl;		                   
}
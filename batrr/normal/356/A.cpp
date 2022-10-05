#include <iostream>
#include <cstdio>
#include <cstdlib>
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

#include <ctime>
#include <cassert> 
 
#define ld long double 
//#define ll long long 
#define f first 
#define s second 
#define pb push_back 
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
 
using namespace std;   
const int maxn=3e5+123,inf=1e9;
long long n,q,t[4*maxn],a,b,c;
vector< pair <int , pair< int , int > > > z;
void push (int k) {
	if (t[k] != -1) {
		t[k*2] = t[k]; 
		t[k*2+1] = t[k];
		t[k] = -1;
	}
}             
void up(int k,int l ,int r ,int ll ,int rr,int val){
	if(ll>rr)
		return;
	if(l==ll && r==rr){ 
		//cout<<k<<endl;
		t[k]=val;
		return ;
	}
	push(k);
	int m=(l+r)/2;
	up(k*2,l,m,ll,min(rr,m),val);
	up(k*2+1,m+1,r,max(ll,m+1),rr,val);	
}         
int get(int k, int l ,int r ,int pos){
	if(l==r)
		return t[k];
	push(k);
	int m=(l+r)/2;
	if(pos<=m)                  
		return get(k*2,l,m,pos);
	return get(k*2+1,m+1,r,pos);	
}
int main(){               
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b>>c;
		z.pb(mp(c,mp(a,b)));
	}
	for(int i=z.size()-1;i>=0;i--){
		a=z[i].s.f,b=z[i].s.s,c=z[i].f,
		up(1,1,n,a,c-1,c);
		up(1,1,n,c+1,b,c);
	}
	for(int i=0;i<n;i++)
		cout<<get(1,1,n,i+1)<<" ";
}
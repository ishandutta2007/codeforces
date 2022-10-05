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
const int maxn=1e5+123,inf=2e9,mod=1e9+7;  
ll t[4*maxn];
ll n,m,p,a;
void up(int v, int tl, int tr , int pos ,int val, int level){
	if(tl==tr){
		t[v]=val;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)
		up(v+v,tl,tm,pos,val,level-1);
	else
		up(v+v+1,tm+1,tr,pos,val,level-1);		
	if(level%2==1)               
		t[v]=(t[v+v] | t[v+v+1]);
	else
		t[v]=(t[v+v] ^ t[v+v+1]);
	return ;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=(1<<n);i++){
		cin>>a;
		up(1,1,(1<<n),i,a,n);
	}                 
	while(m--){
		cin>>p>>a;
		up(1,1,(1<<n),p,a,n);
		cout<<t[1]<<endl;
	}
}
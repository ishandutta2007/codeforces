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
const ll maxn=1e6+12,inf=2e9,mod=1e8; 
pair< ull , ull > h[maxn],p[maxn],b=mp(31,37);
string s;
int n;
pair < ull , ull > geth(int l , int r){
	return mp(
	h[r].f-h[l-1].f*p[r-l+1].f
	,
	h[r].s-h[l-1].s*p[r-l+1].s
	);
}
bool check(int len, pair< ull ,ull > hs){
	for(int i=1;i+len-1<n-1;i++)
		if(geth(i,i+len-1)==hs)
			return true;
	 return false;
}
int main(){          
	cin>>s;
	n=s.size();
	p[0]=mp(1,1);
	for(int i=0;i<n;i++){
		h[i]=mp(h[i-1].f*b.f+s[i]-'a'+1,h[i-1].s*b.s+s[i]-'a'+1);
		p[i+1]=mp(p[i].f*b.f,p[i].s*b.s);
	}
	vector<pair<int , pair< ull,ull> > > v;
	for(int i=1;i<n;i++)
		if(geth(0,i-1)==geth(n-i,n-1))
			v.pb(mp(i,geth(0,i-1)));		
	if(v.empty()|| check(v[0].f,v[0].s)==false){
		cout<<"Just a legend";
		return 0;
	}
	int l=0,r=v.size()-1;
	while(l<=r){
		int m=(l+r)/2;
		if(check(v[m].f,v[m].s))
			l=m+1;
		else
			r=m-1;
	}
	for(int i=0;i<v[l-1].f;i++)
		cout<<s[i];
}
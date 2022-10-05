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
#define op cout<<"BUG"<<endl; 
#define in insert         
#define er erase
using namespace std;
const int maxn=1100;
ld last[maxn],res,mx;
int n,x,r;
void solve(int x){
	res=r;
	for(int i=1;i<maxn;i++){
		ld l=sqrtl(4*r*r-(x-i)*(x-i));
	//	cout<<i<<" "<<l<<" ";
		l=l+last[i];
		res=max(res,l);
	//	cout<<" "<<l<<endl;
	}
	last[x]=res;
	cout<<res<<" ";
}
int main(){
	cin>>n>>r;            
	for(int i=0;i<maxn;i++)
		last[i]=-r;
	cout<<fixed<<setprecision(5);
	while(n--){
		cin>>x;
		solve(x);
	}
}
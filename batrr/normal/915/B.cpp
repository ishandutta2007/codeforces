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
const int maxn=1e5+123,inf=2e9;  
int ans,n,k,l,r;
int main(){
	cin>>n>>k>>l>>r;
	if(k<l)
		ans=l-k,k=l;
	if(k>r)
		ans=k-r,k=r;	
	if(l!=1 && r!=n)
		cout<<r-l+min(k-l,r-k)+2+ans;
	else if(l!=1)
		cout<<k-l+1+ans;
	else if(r!=n)
		cout<<r-k+1+ans;	
	else
		cout<<ans;
}
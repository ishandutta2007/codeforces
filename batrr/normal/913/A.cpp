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
ll n,m,p=1;
int main(){                             
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(p>m){
			cout<<m;
			return 0;
		}
		p*=2;
	}
	cout<<m%p;
	return 0; 
}
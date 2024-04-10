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
const int maxn=1e5+123,inf=1e9,mod=1e9+7;
const ll infl=4e18;
ll a,b,x,y,z;
int main(){     
    cin>>a>>b;
    cin>>x>>y>>z;
	cout<<max(x*2+y-a,0LL)+max(z*3+y-b,0LL);
	return 0;	           
}
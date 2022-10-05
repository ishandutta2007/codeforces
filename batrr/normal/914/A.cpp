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
const ll maxn=2e5+1,inf=2e9,mod=1e9+7; 
ll n,a,ans=-inf;
int main(){
	cin>>n;
	vector<int>v;
	while(n--){
		cin>>a;
		bool u=true;
		for(int i=0;i<=1000;i++)
			if(i*i==a)
				u=0;
		if(u)
			v.pb(a);
	}
	sort(v.begin(),v.end());
	cout<<v[v.size()-1];
}
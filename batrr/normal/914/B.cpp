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
ll n,a,cnt[maxn];
int main(){
	cin>>n;             
	for(int i=0;i<n;i++){
		cin>>a;
		cnt[a]++;
	}              
	for(int i=maxn-1;i>=0;i--){
		if(cnt[i]%2==0)
			continue;
		cout<<"Conan";
		return 0;
	}
	cout<<"Agasa";
}
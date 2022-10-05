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

#define nm "word" 
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
const int maxn=1e6+123,infi=1e9;
const ll infl=1e18; 
int n,cnt[2],x,y;
int main(){              
	//                           IO
	int n;
	cin>>n;      
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x>0)
			cnt[1]++;
	   else
	   		cnt[0]++;
	}
	if(cnt[1]<=1 || cnt[0]<=1)
		cout<<"Yes";
	else
		cout<<"No";
}
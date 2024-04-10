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
const int maxn=1e6+123,inf=1e9; 
int cnt[maxn],n,ans;
int main(){             
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int q=i;q<=j;q++){
				cnt[q]++;
				ans=max(ans,cnt[q]);
			}
		}
	//cout<<cnt[i]<<" ";
	}
   cout<<ans;
}
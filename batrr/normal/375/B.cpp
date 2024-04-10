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
const ll maxn=5e3+1,inf=2e9,mod=1e9+7; 
int ans,n,m,len[maxn][maxn],cnt[maxn];
string s;
int main(){            
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		char s[maxn];
		scanf("%s",s);
		for(int j=1;j<=m;j++){
			if(s[j-1]=='1')
				len[i][j]=len[i][j-1]+1;
		}
	}
	for(int j=1;j<=m;j++){    
		for(int i=1;i<=n;i++)
			cnt[len[i][j]]++;
		int CNT=0;
		for(int i=m;i>=0;i--){
			CNT+=cnt[i];
			ans=max(ans,CNT*i);
			cnt[i]=0;
		}		
	}
	cout<<ans;
}
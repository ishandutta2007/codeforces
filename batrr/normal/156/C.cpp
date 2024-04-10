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
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);

using namespace std;                    
const ll maxn=1e6+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll T,dp[101][2601],n;
string s;
void solve(){         
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
		cnt+=s[i]-'a';
   	cout<<(dp[s.size()][cnt]-1+mod)%mod<<endl;
}
int main(){
	Bystro
	dp[0][0]=1;
	for(int len=1;len<=100;len++){
		for(int cnt=0;cnt<=2600;cnt++){
			for(int q=0;q<26;q++)
				if(cnt-q>=0)
					dp[len][cnt]+=dp[len-1][cnt-q];
			dp[len][cnt]%=mod;
		}
	} 
	cin>>T;
	while(T--)
		solve();	
}
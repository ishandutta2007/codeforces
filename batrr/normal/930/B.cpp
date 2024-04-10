#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring> 
#include <string> 
#include <string.h>
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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=2e5+123,N=5010,inf=1e9,mod=1e9+7,INF=1e18;
const ld eps=1e-12,PI=3.141592653589793238462643383279;  
string s,t;
int cnt[50];
vector<string>v[50];
int ans;
int main(){                           
	cin>>s;
	for(int i=0;i<s.size();i++){
		t="";
		for(int j=0;j<s.size();j++)
			t+=s[(j+i)%s.size()];
		v[t[0]-'a'].pb(t);
	}
	for(int i=0;i<50;i++){
		int mx=0;
		if(v[i].size()==0)
			continue;
		for(int q=1;q<s.size();q++){
			for(int j=0;j<50;j++)
				cnt[j]=0;
			
			for(int j=0;j<v[i].size();j++)
				cnt[v[i][j][q]-'a']++;
			
			int val=0;
			for(int j=0;j<50;j++){
				if(cnt[j]==1)
					val++;
			}
			mx=max(mx,val);
        }			
        ans+=mx;
	}
	cout<<fixed<<setprecision(20)<<(ld)ans/s.size();
}
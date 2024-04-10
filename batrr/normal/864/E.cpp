#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")


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
#define ld double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
inline void read(int &x){char ch;bool f=0;int a=0;while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));if(ch!='-')a*=10,a+=ch-'0';else f=1;while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';if(f)a=-a;x=a;}

const ll maxn=4100,N=400,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
struct item{
	int val,cost,id,mx;
};
bool cmp( item a, item b){
	return a.mx<b.mx;
}
int n;
ll dp[102][2500],p[102][2500];
item  a[150];
int main(){
	//IO       
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cost>>a[i].mx>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int w=a[i].cost,h=a[i].val;
		for(int t=0;t<2500;t++){
			dp[i][t]=dp[i-1][t];
			p[i][t]=t;
		}
		for(int t=0;t+w<a[i].mx;t++){
			if( dp[i][t+w]<dp[i-1][t]+h){
				dp[i][t+w]=dp[i-1][t]+h;
				p[i][t+w]=t;
				//cout<<i<<" "<<t+w<<" "<<t<<endl;
			}
		}
	}
	vector<int>ans;
	ll mx=0;
	for(int t=0;t<2500;t++)
		mx=max(mx,dp[n][t]);
	cout<<mx<<endl;
	for(int t=0;t<2500;t++){
		if(mx==dp[n][t]){
			int cur=t;
			for(int i=n;i>=1;i--){
				//cout<<i<<" "<<cur<<" "<<p[i][cur]<<endl;
            	if(p[i][cur]==cur)
					continue;
				ans.pb( a[i].id );
				cur=p[i][cur];
			}
			break;
		}
	}	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[ans.size()-1-i]<<" ";
}
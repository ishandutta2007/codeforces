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
using namespace std;                    
const ll maxn=5000,inf=2e18+1,mod=1e9+7;  
ll n,f[700][100],ans=4e18;
vector<int>v;
bool used[maxn];
int ln(ll g){
	int res=0;
	while(g!=0)
		g/=10,res++;
	return res;
}
void rec(int cur,int last,int len,ll val){
	if(cur==1){
		ans=min(val,ans);
		return ;
	}
	for(int i=last;i>1;i--){
		if(cur%i==0){
			if(f[len][i-1]!=0 && ln(val)+ln(f[len][i-1])<=19  && val*f[len][i-1]<=inf)
				rec(cur/i,i,len+1,val*f[len][i-1]);
		} 
	}
}
int main(){
	for(int i=2;i<maxn;i++){
		if(!used[i]){
			v.pb(i);
			for(int  j=i;j<maxn;j+=i)
				used[j]=1;
		}
	}              
	for(int i=0;i<v.size();i++){
		f[i][0]=1;
		for(int j=1;j<100;j++){
			f[i][j]=f[i][j-1]*v[i];
			if(ln(v[i])+ln(f[i][j])<=18  && f[i][j]>inf)
				f[i][j]=0;
		}
	}         
	cin>>n;
	rec(n,99,0,1);
	cout<<ans;
}
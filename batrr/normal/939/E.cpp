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
const ll maxn=1e6+113,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;
ll pre[maxn],mx,n,q,type;
ld get(int len){
	return mx-(pre[len]+mx)/(len+1.0);
}
int main(){   
	ios_base:: sync_with_stdio(false);
	cin>>q;
	while(q--){                      
	    cin>>type;
		if(type==1){
			cin>>mx;
			pre[n+1]=pre[n]+mx;
			n++;
		}	
		else
		{
			ll l=0,r=n-1;
			for(int i=0;l<=r && i<=20;i++){         
				int m1=l+(r-l)/3;
				int m2=r-(r-l)/3;
				if(get(m1)>get(m2))
					r=m2;
				else
					l=m1;
			}
			ld res=0.0;
			for(int i=max(0ll,l-100);i<=min(n-1,l+100);i++){
				if(get(i)>res)
					res=get(i);                     /*
				cout<<i<<" "<<get(i)<<endl;        */
			}                              
			cout<<fixed<<setprecision(6)<<res<<endl;
		}
	}
}
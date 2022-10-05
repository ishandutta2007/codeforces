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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=2e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
string s;
set < int > st1,st2;
vector< vector<int> > ans;

int main(){        
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			st1.insert(i+1);
		else             
			st2.insert(i+1);
	
	set<int>::iterator it;
	while(!st1.empty()){
		vector<int>res;
		res.pb(*st1.begin());
		st1.erase(st1.begin());
		
		while(true){
			it=st2.lower_bound(res.back());
			if(it==st2.end())
				break;
			int j=*it;
			
			it=st1.lower_bound(j);
			if(it==st1.end())
				break;
			int i=*it;
			
			res.pb(j);
			res.pb(i);   
			
			st2.erase(j);
			st1.erase(i);
		}
		
		ans.pb(res);
	} 
	if(!st1.empty() || !st2.empty()){
		cout<<-1;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].size()<<" ";
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}
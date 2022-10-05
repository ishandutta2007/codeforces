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
const ll maxn=1e6+132,mod=1e9+7;       
int n;
bool used[maxn];
int main(){	
	Bystro
	cin>>n;                    
	vector < pair < int , int > > ans;
	for(int i=3;i+i<=n;i++){
	
		bool p=0;
		for(int j=2;j*j<=i;j++)
			p|= (i%j==0);
		if(p)
			continue;
		
		vector<int>v;
		for(int j=i+i+i;j<=n;j+=i)
			if(!used[j])
				v.pb(j);	
		int j=0;
		if(v.size()%2==0)	
			v.pb(i+i);
		v.pb(i);
		while(j+1<v.size()){
			ans.pb(mp(v[j],v[j+1]));
			used[v[j]]=1;
			used[v[j+1]]=1;
			j+=2;
		}	
	}
	
	vector<int>v;
	int i=2;
	for(int j=i;j<=n;j+=i)
		if(!used[j])
			v.pb(j);	
	int j=0;
	while(j+1<v.size()){
		ans.pb(mp(v[j],v[j+1]));
		used[v[j]]=1;
		used[v[j+1]]=1;
		j+=2;
	}
	cout<<ans.size()<<endl;                     
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].f<<" "<<ans[i].s<<endl;  
}
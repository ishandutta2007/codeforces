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
int n,q,x,ans[maxn],a[maxn],open[maxn];
int main(){	
	Bystro
	cin>>n;                                                
	for(int i=1;i<=n;i++)
		cin>>a[n-i+1];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x;
		open[n-x+1]++;
	}
	stack<int>st;
	for(int i=1;i<=n;i++){
		if(open[i]){
			st.push(i);
			continue;
		}

		if(!st.empty() && a[st.top()] == a[i]){
			ans[st.top()]=a[i];
			ans[i]=-a[i];
			st.pop();
		}else
			st.push(i);
	}

	if(st.empty()==0){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<-ans[n-i+1]<<" ";
}
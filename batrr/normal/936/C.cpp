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
const ll maxn=1e7+132,N=2e5,inf=1e9,mod=1e9+9;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
string s,pre,suf,tmp;
int n;
vector<int>ans;
int main(){ 
	//IO
	cin>>n>>pre>>s;
	
	int l=n/2+1,r=n/2+1;
	queue<int>q;
	q.push(n/2+1);
	while( !(l==1 && r==n) ){
		if(l!=1)
			q.push(--l);
		if(r!=n)
			q.push(++r);
	}
	

	while(!q.empty()){
		char x=s[q.front()-1];
		int id=-1;
		q.pop();

		for(int i=0;i<pre.size();i++)
			if(pre[i]==x)
				id=i;	
		
		if(id==-1){
			cout<<-1;
			return 0;
		}
		
		int a,b,c;
		b=id;
		c=pre.size()-1-b;
		a=n-c-b-1;  
		ans.pb(c+1);
		ans.pb(b);
		ans.pb(a+1);

		for(int i=id-1;i>=0;i--)
			tmp+=pre[i];

		for(int i=pre.size()-1;i>=id+1;i--)
			tmp+=pre[i];

		for(int i=0;2*i<suf.size();i++)
			swap(suf[i],suf[suf.size()-1-i]);
		suf+=x;
		pre=tmp;
		tmp.clear();
		//cout<<suf<<" "<<pre<<endl;
	}
	if(s!=suf)
		ans.pb(n);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
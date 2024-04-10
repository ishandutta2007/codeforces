#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

const ll maxn=2123,MX=1e9,inf=1e9;
ll n,k,ans,a;
priority_queue < ll > q;
int main(){      
	cin>>n;
	cin>>a;
	q.push(a);
	for(int i=1;i<n;i++){
		cin>>a;      
		a-=i;
		ans+=max(0ll,q.top()-a);
	     q.push(a);
	     q.push(a);
	     q.pop();
	}
	cout<<ans;	
}
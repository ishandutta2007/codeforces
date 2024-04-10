#include <bits/stdc++.h>
 
#define nm "" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e6+123,mod=1e9+7,N=2e6+123;
string s;            
ll n,k1,k2,k,a[maxn],b[maxn],ans;

int main(){
	cin>>n>>k1>>k2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	priority_queue <ll>q;
	for(int i=1;i<=n;i++)
		q.push(abs(a[i]-b[i]));
	k=k1+k2;
	while(k--){
		ll x=q.top();
		q.pop();
		if(x==0)    
			q.push(x+1);
		else
			q.push(x-1);
	}
	while(!q.empty()){
		ans+=q.top()*q.top();
		q.pop();
	}
	cout<<ans;
}
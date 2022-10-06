// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
ll n,k,a[maxn];
string s;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(k==0){
		if(a[1]==1)
			cout<<-1;
		else
			cout<<1;
		return 0;	
	}
	if(a[k]==a[k+1])
		cout<<-1;
	else
   		cout<<a[k];
}
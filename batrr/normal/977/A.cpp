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
ll n,x,y,a[maxn];
string s;
int main(){
	cin>>n>>x;
	while(x--){
		if(n%10==0)
			n/=10;
		else
			n--;
	}
	cout<<n;
}
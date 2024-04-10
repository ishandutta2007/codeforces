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
const ll maxn=5e4+123,inf=1e8,mod=1e9+7,block=200,N=5000+123;
ll n,x,y,z,a[maxn],b[maxn];
string s,t;
int main(){
	#ifdef LOCAL
	//	freopen ("test.in", "r", stdin);
	#endif
	cin>>n;
	if(n==0){
		cout<<"0"<<endl;
		return 0;
	}       
	if(n%2)
		cout<<(n+1)/2;
	else
		cout<<n+1;		                               
}
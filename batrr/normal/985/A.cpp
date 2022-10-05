// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=6e6+123,inf=1e8,mod=1e9+7,block=200,N=1e6;
int n,a[maxn],x,y;
string s,t;
int main(){
	
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif              
	cin>>n;
	for(int i=1;i<=n/2;i++)
		cin>>a[i];
	sort(a+1,a+1+n/2);
	for(int i=1;i<=n/2;i++){
		x+=abs(i+i-1-a[i]);
		y+=abs(i+i-a[i]);
		//cout<<x<<" "<<y<<endl;
	}
	cout<<min(x,y);
}
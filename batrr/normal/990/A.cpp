#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=3e5+123,inf=1e18,LOG=18,block=450;
int main(){
    #ifdef LOCAL                         
		freopen ("test.in", "r", stdin);
    #endif
    IOS
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	cout<<min( n%m * b , (m-n%m)*a );
}
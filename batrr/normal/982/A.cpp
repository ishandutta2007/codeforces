// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e8,mod=1e9+7,block=200,N=2053;
ll n,x,y,z,a[maxn];
string s,t;
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
//	#else
//		freopen ("jumper.in", "r", stdin);
//		freopen ("jumper.out", "w", stdout);
	#endif               
	cin>>n;
	cin>>s;
	bool ok=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			if(i>0 && s[i-1]=='1')
				ok=0;
			if(i+1<n && s[i+1]=='1')
				ok=0;
		}else{
			if( (i==0 || (i>0 && s[i-1]=='0') ) && (i==n-1 || (i+1<n && s[i+1]=='0') ) )
				ok=0;
		
		}
    }
    if(ok)
    	cout<<"yes";
   	else
   		cout<<"no";	
}
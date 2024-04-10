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
const ll maxn=2123,inf=1e8,mod=1e9+7,block=200,N=1e6;
int n,m,cnt[maxn];
string s[maxn];
int main(){
	
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif              
	cin>>n>>m;        
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++)
			if(s[i][j]=='1')
				cnt[j]++;
	}
	for(int i=0;i<n;i++){
		bool ok=1;
		for(int j=0;j<m;j++)
			if(s[i][j]=='1' && cnt[j]<=1)
				ok=0;
		if(ok){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

}
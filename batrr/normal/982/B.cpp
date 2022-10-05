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
int n,w[maxn],ans[maxn];
string s;
set< pair < int,  int > > st1,st2;
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
//	#else
//		freopen ("jumper.in", "r", stdin);
//		freopen ("jumper.out", "w", stdout);
	#endif               
	cin>>n;                                                       
	for(int i=1;i<=n;i++){
		cin>>w[i];
		st1.insert(mp(w[i],i));
	}
	cin>>s;
	for(int i=0;i<n+n;i++){
		if(s[i]=='0'){
			cout<<(*st1.begin()).s<<" ";
			st2.insert(mp(-(*st1.begin()).f,(*st1.begin()).s));
			st1.erase(st1.begin());
		}else{
			cout<<(*st2.begin()).s<<" ";
			st2.erase(st2.begin());
		}
	}

}
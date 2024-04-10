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
string s;
int n,mx,ans,cnt[1000][1000];
int main(){
	cin>>n;
	cin>>s;
	for(int i=1;i<s.size();i++){
		mx=max(mx,++cnt[s[i-1]][s[i]]);
		if(mx==cnt[s[i-1]][s[i]])
			ans=i-1;
	}
	cout<<s[ans]<<s[ans+1];
}
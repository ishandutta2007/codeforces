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
ll n,cur,ans,l[maxn],r[maxn];     
string s[maxn];
int main(){
    #ifdef LOCAL                         
		freopen ("test.in", "r", stdin);
    #endif
    IOS
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];     
	for(int i=0;i<n;i++){
		cur=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='(')
				cur++;
			else
				cur--;
			if(cur<0)
				break;
		}
		if(cur>=0)
			l[cur]++;
	}

	for(int i=0;i<n;i++){
		cur=0;
		for(int j=s[i].size()-1;j>=0;j--){
			if(s[i][j]==')')
				cur++;
			else
				cur--;
			if(cur<0)
				break;
		}
		if(cur>=0)
			r[cur]++;
	}
	for(int i=0;i<maxn;i++)
		ans+=l[i]*r[i];
	cout<<ans;
}
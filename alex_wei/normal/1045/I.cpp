#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+2;
map <int,int> f;
int n,p[26];
bool q[1<<26];
ll ans;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		memset(p,0,sizeof(p));
		int z=0;
		for(int j=0;j<s.size();j++)
			p[s[j]-'a']=!p[s[j]-'a'];
		for(int j=0;j<26;j++)
			z|=p[j]<<j;
		q[z]=1;
		f[z]++;
	}
	for(int i=0;i<(1<<26);i++)
		if(q[i]){
			ans+=1ll*f[i]*(f[i]-1);
			for(int j=0;j<26;j++)
				ans=ans+1ll*f[i^(1<<j)]*f[i];
		}
	cout<<ans/2;
	return 0;
}
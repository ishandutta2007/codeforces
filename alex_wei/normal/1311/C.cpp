#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,t,g[200005];
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		for(int i=0;i<m;i++)cin>>g[i],g[i]=g[i]-1;
		sort(g,g+m);
		int buc[26],ans[26];
		memset(buc,0,sizeof(buc));
		memset(ans,0,sizeof(ans));
		int pos=0;
		for(int i=0;i<n;i++){
			buc[s[i]-'a']++;
			while(pos<m&&g[pos]==i){
				for(int j=0;j<26;j++)ans[j]+=buc[j];
				pos++;
			}
		}
		for(int i=0;i<26;i++)cout<<buc[i]+ans[i]<<' ';
		puts("");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
string s[N];
map<string,bool>vis,t;

bool cmp(int x,int y){
	return s[x]<s[y];
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i];
		vis.clear();
		t.clear();
		int ans=0;
		for(int i=1;i<=n;++i)vis[s[i]]=t[s[i]]=1;
		for(int i=1;i<=n;++i){
			if(vis[s[i]]){
				if(t[s[i]]){
					t[s[i]]=0; 
					continue;
				} 
				ans++;
				for(int k='0';k<='9';++k){
					string t=s[i];
					t[0]=k;
					if(!vis[t]){
						s[i]=t;
						break;
					}
				}
			}
			vis[s[i]]=1; 
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;++i)cout<<s[i]<<endl;
	}
}
/*

*/
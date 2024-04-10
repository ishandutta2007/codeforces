#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

string s;
int cnt[N][26];
ll tot[26][26];

int main(){
	cin>>s;
	int n=s.size();
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i-1]-'a']++;
	}
	ll ans=*max_element(cnt[n],cnt[n]+26);
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j){
			tot[s[i-1]-'a'][j]+=cnt[i-1][j];
			ans=max(ans,tot[s[i-1]-'a'][j]);
		}
	}
	cout<<ans<<endl;
}
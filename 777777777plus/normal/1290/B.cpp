#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

string s;
int Q,cnt[N][26];

int main(){
	cin>>s>>Q;
	int n=s.size();
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i-1]-'a']++;
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		int c=0;
		for(int j=0;j<26;++j)if(cnt[r][j]!=cnt[l-1][j])++c;
		if(c>2||s[l-1]!=s[r-1]||l==r)puts("Yes");
		else puts("No");
	}
}
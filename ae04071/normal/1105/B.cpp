#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n,k,cnt[26];
char str[200100];
int main() {
	scanf("%d%d%s",&n,&k,str);
	for(int i=0,j;i<n;i=j) {
		for(j=i;j<n && str[i]==str[j];j++);
		cnt[str[i]-'a'] += (j-i)/k;
	}
	int mx=0;
	for(int i=0;i<26;i++) mx=max(mx,cnt[i]);
	printf("%d\n",mx);
	return 0;
}
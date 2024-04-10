#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,k;
char s[N],ans[N];
int cnt[26];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		cin>>s+1;
		if(n%k){
			puts("-1");
			continue;
		}
		int p=0;
		memset(cnt,0,sizeof(cnt));
		bool flag=0;
		bool gg=0;
		for(int i=1;i<=n;++i){
			int l=flag?0:s[i]-'a';
			bool use=0;
			for(int t=l+(gg?1:0);t<26;++t){
				cnt[t]=(cnt[t]+1)%k;
				int c=0;
				for(int j=0;j<26;++j)
				if(cnt[j]){
					c+=k-cnt[j];
				}
				if(c>n-i){
					cnt[t]=(cnt[t]-1+k)%k;
					continue;
				}
				ans[i]=t+'a';
				if(t>l)flag=1;
				use=1;
				gg=0;
				break;
			}
			if(!use){
				assert(!flag);
				--i;
				int l=s[i]-'a';
				cnt[l]=(cnt[l]-1+k)%k;
				--i;
				gg=1;
			}
		}
		for(int i=1;i<=n;++i)putchar(ans[i]);
		puts("");
	}
}
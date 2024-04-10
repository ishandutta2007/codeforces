#include<bits/stdc++.h>
#define ll long long
#define N 115
using namespace std;
int n,ans;
char s[N];
bool vis[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i = 25;i >= 1;--i){
		for(int j = 1;j <= n;++j){
			if(s[j]-'a'==i){
				int pos = j-1;
				while(pos > 0&&(vis[pos]==1||s[pos]==s[j])) pos--;
				if(pos > 0&&s[pos] == s[j]-1) vis[j] = 1;
				else{
					int pos = j+1;
					while(pos <= n&&(vis[pos]==1||s[pos]==s[j])) pos++;
					if(pos <= n&&s[pos] == s[j]-1) vis[j] = 1;
				}
			}
		}
	}
	for(int i = 1;i <= n;++i) if(vis[i]) ans++;
	printf("%d",ans);
	return 0;
}
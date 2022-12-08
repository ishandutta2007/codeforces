#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,cnt[21][21];
char a[N],b[N];
void Solve(){
	for(int i=1;i<=n;++i)
	if(b[i]<a[i]){
		puts("-1");
		return;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)
	if(a[i]!=b[i]){
		cnt[a[i]-'a'][b[i]-'a']++;
	}
	int ans=0;
	for(int i=0;i<20;++i){
		for(int j=i+1;j<20;++j)
		if(cnt[i][j]){
			for(int k=0;k<20;++k){
				cnt[j][k]+=cnt[i][k];
			}
			ans++;
			break;
		}
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		Solve();
	}
}
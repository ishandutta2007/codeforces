#include<bits/stdc++.h>
#define ll long long
#define N 1000015
using namespace std;
char s[N];
ll ans;
int n,cnt,lst,maxx;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	lst = 0;
	for(int i = 1;i <= n;++i){
		if(s[i]==')') cnt++;
		else cnt--;
		if(cnt == 0){
			if(maxx>0)ans += (i-lst);
			lst = i;
			maxx = 0;
		}else{
			maxx = max(maxx,cnt);
		}
	}
	if(cnt!=0) puts("-1");
	else printf("%lld",ans);
	return 0;
}
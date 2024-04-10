#include<bits/stdc++.h>
#define ll long long
#define N
using namespace std;
int t,n,k;
ll a[105],cnt[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i <= n;++i) cin>>a[i];
		memset(cnt,0,sizeof(cnt));
		for(int i = 1;i <= n;++i){
			int j = 0;
			while(a[i] > 0){
				cnt[j] += a[i]%k;
				a[i] /= k;
				j++;
			}
		}
		int flag = 0;
		for(int i = 0;i <= 80;++i)
			if(cnt[i]>1) flag = 1;
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
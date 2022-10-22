//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
char s[N],t[N];
int n,m,tag[N],pp[N];
int main()
{
	int T;
	scanf("%d",&T); 
	while (T--)
	{
		scanf("%s %s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=1;i<=n;++i)tag[i]=0;
		int now=m;
		for(int i=n;i>=1;--i){
			if(now&&t[now]==s[i]){
				tag[i]=1;
				now--;
			}
		}
		if(now){
			puts("NO");
			continue;
		}
	//	for(int i=1;i<=n;++i)cout<<tag[i]<<" ";puts("");
		bool G=0;
		for(int i=1;i<=n;++i){
			if(tag[i]){
				pp[s[i]-'A']=1;
			}
			else{
				if(pp[s[i]-'A']){
					G=1;
				}
			}
		}
        if(G)puts("NO");
        else puts("YES");
        for(int i=0;i<=50;++i)pp[i]=0;
        for(int i=1;i<=n;++i)tag[i]=0;
	}
	return 0;
}
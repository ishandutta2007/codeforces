#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int T,r,g,b,w;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&r,&g,&b,&w);
		int cnt = 0;
		if(r&1) cnt++;
		if(g&1) cnt++;
		if(b&1) cnt++;
		if(w&1) cnt++;
		if(cnt <= 1) puts("Yes");
		else{
			if(r>0 && b>0 && g>0){
				cnt = 4-cnt;
			}
			if(cnt <= 1) puts("Yes");
			else{
				puts("No");
			}
		}
	}
	return 0;
}
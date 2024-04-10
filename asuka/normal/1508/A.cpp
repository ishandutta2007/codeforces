#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,ac,bc,cc;
char a[N],b[N],c[N],ans[N];
void solve(char s[],char t[],int x){
	rep(i,1,n*4) ans[i] = '\0';
	if(x == 0){
		rep(i,1,2*n) s[i] = '1'-s[i]+'0',t[i] = '1'-t[i]+'0';
	}
	int sc,tc; sc = tc = 0;
	rep(i,1,n*2) sc += s[i]-'0',tc += t[i]-'0';
	// printf("%s %s\n",s+1,t+1);
	if(sc < tc) swap(s,t);
	int p = 0,tot = 0;
	rep(i,1,n*2){
		if(t[i]=='0') ans[++tot] = '0';
		else{
			while(s[p+1] != '1') ans[++tot] = s[++p];
			ans[++tot] = s[++p];
		}
	}
	while(p+1 <= n*2) ans[++tot] = s[++p];
	if(x == 0){
		rep(i,1,tot) ans[i] = '1'-ans[i]+'0';
	} 
	rep(i,1,tot) printf("%c",ans[i]);
	printf("\n");
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ac = bc = cc = 0;
		scanf("%s%s%s",a+1,b+1,c+1);
		rep(i,1,n*2) ac += a[i]-'0';
		rep(i,1,n*2) bc += b[i]-'0';
		rep(i,1,n*2) cc += c[i]-'0';
		if(ac >= n){
			if(bc >= n) solve(a,b,1);
			else if(cc >= n) solve(a,c,1);
			else solve(b,c,0);
		}else{
			if(bc <= n) solve(a,b,0);
			else if(cc <= n) solve(a,c,0);
			else solve(b,c,1);
		}
	}
	return 0;
}
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
int n,k,pre[N];
char s[N];
int q(int l,int r){
	if(l>r) return 0;
	return pre[r]-pre[l-1];
}
bool xian(){
	rep(i,1,n-k+1){
		int l = i,r = i+k-1;
		int sum = q(1,l-1)+q(r+1,n);
		if(sum == 0 || sum+k == n) return 1;
	}
	return 0;
}
bool hou(){
	if(k == 1 || k+k < n) return 0;
	int len = n-k-1;
	rep(i,2,len){
		if(s[i] != s[i-1] || s[n-i+1] != s[n-i+2]) return 0;
	}
	if(s[1] == s[n]) return 0;
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,n) pre[i] = pre[i-1]+s[i]-'0';
	if(xian()) puts("tokitsukaze");
	else if(hou()) puts("quailty");
	else puts("once again");
	return 0;
}
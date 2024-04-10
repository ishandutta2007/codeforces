#include<bits/stdc++.h>
#define ll long long
#define N 205
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
#define all(x) x.begin(),x.end()
using namespace std;
int n,q,t,zero[N],one[N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d",&n,&q);
 		scanf("%s",s+1);
 		rep(i,1,n) zero[i] = zero[i-1]+(s[i]-'0'==0);//,cout << zero[i] << ' ';
 		rep(i,1,n) one[i] = one[i-1]+(s[i]-'0'==1);
 		while(q--){
 			int l,r,res = 0;
 			scanf("%d%d",&l,&r);
 			if(s[l]-'0'==0 && zero[l-1]>0) res = 1;
 			if(s[l]-'0'==1 && one[l-1]>0) res = 1;
 			if(s[r]-'0'==0 && zero[n]-zero[r]>0) res = 1;
 			if(s[r]-'0'==1 && one[n]-one[r]>0) res = 1;
 			if(res) puts("YES");
 			else puts("NO");
 		}
 	}
	return 0;
}
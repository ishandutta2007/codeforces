#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
#define SZ(x) ((int)x.size())
using namespace std;
char s[N],tmp[N];
int n,m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%s",s+1);
 	n = strlen(s+1);
 	scanf("%d",&m);
 	while(m--){
 		int l,r,k; scanf("%d%d%d",&l,&r,&k);
 		k %= (r-l+1);
 		if(k == 0) k = r-l+1;
 		int pos = r-k+1;
 		rep(i,1,r-l+1) tmp[i] = s[(pos+i-1 > r) ? (pos+i-1) - (r-l+1) : pos+i-1];
 		// rep(i,1,r-l+1) printf("%c ",tmp[i]); printf("\n");
 		rep(i,1,r-l+1) s[l+i-1] = tmp[i];
 	}
 	printf("%s\n",s+1);
	return 0;
}
/*
abacaba
1
3 6 1
*/
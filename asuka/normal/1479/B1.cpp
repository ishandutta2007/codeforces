#include<bits/stdc++.h>
#define ll long long
#define N 114514
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
VI b,w;
int n,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]);
 	b.pb(-1);w.pb(-1);
 	rep(i,1,n){
 		if(w.back() == a[i] && b.back() == a[i]) continue;
 		if(w.back() == a[i] && b.back() != a[i]) b.pb(a[i]);
 		else if(w.back() != a[i] && b.back() == a[i]) w.pb(a[i]);
 		else {
 			if(w.back() == a[i+1]) w.pb(a[i]);
 			else b.pb(a[i]);
 		}
 	}
 	int ans = 0;
 	rep(i,1,(int)b.size()-1) if(b[i] != b[i-1]) ans++;
 	rep(i,1,(int)w.size()-1) if(w[i] != w[i-1]) ans++;
 	printf("%d\n",ans);
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
int t, n, a[N];
bool ispa(VI vec) {
	VI rvec = vec;
	reverse(all(rvec));
	return vec == rvec;
}
bool check(int x) {
	VI vec;
	rep(i, 1, n) if(a[i] != x) vec.pb(a[i]);
	return ispa(vec);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int l = 1, r = n;
		while(l < r && a[l] == a[r]) {
			l++;
			r--;
		}
		if(l >= r) puts("YES");
		else if(check(a[l]) || check(a[r])) puts("YES");
		else puts("NO");
	}
	return 0;
}
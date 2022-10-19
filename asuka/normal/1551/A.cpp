#include<bits/stdc++.h>
#define ll long long
#define N
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
int T, n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int c = n / 3;
		printf("%d %d\n", c + (n % 3 == 1) , c + (n % 3 == 2));
	}
	return 0;
}
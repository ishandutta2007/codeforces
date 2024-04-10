#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

int n, tmp, top;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int ans[MAXN];

int st[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	st[top++]=0;
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		while (a[st[top-1]]>=a[i]) top--;
		l[i]=st[top-1];
		st[top++]=i;
	}
	top=0;
	st[top++]=n+1;
	for (int i=n; i; i--){
		while (a[st[top-1]]>=a[i]) top--;
		r[i]=st[top-1];
		st[top++]=i;
	}
	
	//for (int i=1; i<=n; i++) cerr<<r[i]-l[i]-1<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<l[i]<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<r[i]<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<r[i]<<' ';cerr<<endl;
	
	for (int i=1; i<=n; i++) ans[r[i]-l[i]-1]=max(ans[r[i]-l[i]-1], a[i]);
	for (int i=n-1; i; i--) ans[i]=max(ans[i], ans[i+1]);
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int n, m, k, x, y;
ll tmp;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int d[MAXN];
ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<m; i++) scanf("%d %d %d", &l[i], &r[i], &d[i]);
	for (int i=0; i<k; i++){
		scanf("%d %d", &x, &y);
		B[x-1]++;
		B[y]--;
	}
	for (int i=0; i<m; i++){
		tmp+=B[i];
		//cerr<<tmp<<' ';
		A[l[i]-1]+=tmp*d[i];
		A[r[i]]-=tmp*d[i];
	}
	//cerr<<endl;
	tmp=0;
	for (int i=0; i<n; i++){
		tmp+=A[i];
		//cerr<<tmp<<' ';
		cout<<tmp+a[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}
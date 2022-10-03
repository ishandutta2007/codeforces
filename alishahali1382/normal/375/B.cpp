#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 5010;

int n, m, ans;
int A[MAXN][MAXN];
int cnt[MAXN];
string s[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>s[i];
	for (int i=0; i<n; i++) A[i][m-1]=(s[i][m-1]=='1');
	for (int i=0; i<n; i++){
		for (int j=m-2; j>=0; j--) A[i][j]=(s[i][j]=='1')*(A[i][j+1]+1);
	}
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) cerr<<A[i][j]<<' ';cerr<<endl;
	}*/
	
	for (int j=0; j<m; j++){
		fill(cnt, cnt+m+1, 0);
		for (int i=0; i<n; i++) cnt[A[i][j]]++;
		ans=max(ans, cnt[m]*m);
		for (int i=m-1; i; i--){
			cnt[i]+=cnt[i+1];
			ans=max(ans, cnt[i]*i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
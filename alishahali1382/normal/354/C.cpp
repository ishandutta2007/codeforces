#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define kill(x) return cout<<x, 0;
const int MAXN = 1000010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[1000010];
long long cnt[1000010];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		cnt[A[i]+1]--;
		cnt[max(1, A[i]-k)]++;
	}
	sort(A+1, A+n+1);
	for (int i=1; i<MAXN; i++) cnt[i]+=cnt[i-1];
	for (int i=1; i<MAXN; i++) for (int j=2*i; j<MAXN; j+=i) cnt[i]+=cnt[j];
	
	for (int i=A[1]; i; i--) if (cnt[i]>=n) kill(i)	
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 998244353;
const int MAXN = 2000010;

int n, ans, x;
int A[MAXN];
int cnt[MAXN];
int last[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		cnt[A[i]]++;
	}
	n=0;
	for (int i=1; i<MAXN; i++){
		if (cnt[i]) A[n++]=i;
		last[i]=max(last[i-1], (cnt[i]>0)*i);
	}
	for (int x=0; x<n; x++){
		int i=A[x];
		//cerr<<i<<endl;
		for (int j=2*i; j<MAXN; j+=i){
			if (j-i<last[j-1]) ans=max(ans, last[j-1]%i);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300 * 1000 + 10;

int n, m;
ll s, tmp;

ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		s+=A[i];
	}
	cin>>m;
	for (int i=0; i<m; i++){
		cin>>B[i];
		s-=B[i];
	}
	if (s){
		cout<<-1<<endl;
		return 0;
	}
	int i=0, j=0;
	int ans=0;
	ll s=0;
	for (; i<n; i++){
		s+=A[i];
		while (j<m && s>0) s-=B[j++];
		if (s==0) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
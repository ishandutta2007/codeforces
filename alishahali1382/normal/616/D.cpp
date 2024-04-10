#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 998244353;
const int MAXN = 1000010;

int n, ans, k, l, r;
int A[MAXN];
int cnt[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	
	for (int i=0, j=0; i<n; i++){
		cin>>A[i];
		if (!(cnt[A[i]]++)) k--;
		while (j<i && k<0){
			if (!(--cnt[A[j++]])) k++;
		}
		if (ans<i-j+1){
			l=j+1;
			r=i+1;
			ans=r-l;
		}
	}
	cout<<l<<' '<<r<<endl;
	return 0;
}
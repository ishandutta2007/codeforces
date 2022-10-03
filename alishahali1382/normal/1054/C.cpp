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

int n, a, b, k, x, y, ans, tmpl, tmpr;
int A[MAXN];
int l[MAXN];
int r[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>l[i];
	for (int i=0; i<n; i++) cin>>r[i];
	for (int i=0; i<n; i++) A[i]=n-(l[i]+r[i]);
	for (int i=0; i<n; i++){
		tmpl=tmpr=0;
		for (int j=0; j<i; j++){
			if (A[j]>A[i]) tmpl++;
		}
		for (int j=i+1; j<n; j++){
			if (A[j]>A[i]) tmpr++;
		}
		if (tmpl!=l[i] || tmpr!=r[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for (int i=0; i<n; i++) cout<<A[i]<<' ';
	cout<<endl;
	return 0;
}
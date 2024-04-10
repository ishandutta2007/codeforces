#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 200010;

int n;
pii A[MAXN];
int B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i].first;
		A[i].first+=i;
		A[i].second=i;
	}
	sort(A, A+n);
	for (int i=0; i<n; i++){
		B[i]=A[i].first-i;	
	}
	for (int i=1; i<n; i++){
		if (B[i-1]>B[i]){
			cout<<":("<<endl;
			return 0;
		}
	}
	for (int i=0; i<n; i++) cout<<B[i]<<' ';cout<<endl;
	return 0;
}
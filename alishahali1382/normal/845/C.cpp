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

int n, l, r, tmp;
int A[2*MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>l>>r;
		A[2*i]=2*l;
		A[2*i+1]=2*r+1;
	}
	sort(A, A+2*n);
	for (int i=0; i<2*n; i++){
		if (A[i]%2) tmp--;
		else tmp++;
		if (tmp>2){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
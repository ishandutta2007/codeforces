#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 100010;

int n;
int A[MAXN];
int B[MAXN];
bool ans[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		B[A[i]]=i;
	}
	for (int i=n; i; i--){
		for (int j=((B[i]-1)%i+1); j<=n; j+=i){
			ans[B[i]]=1;
			if (j!=B[i] && ans[j]==1){
				ans[B[i]]=0;
				//cerr<<i<<' '<<j<<endl;
				break ;
			}
		}
	}
	for (int i=1; i<=n; i++){
		if (!ans[i]) cout<<"A";
		else cout<<"B";
	}
	return 0;
}
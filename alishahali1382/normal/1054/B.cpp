#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int n, a, b, k, x, y, ans;
int A[MAXN];
bool mark[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		if (A[i] && (A[i]>n || !mark[A[i]-1])){
			cout<<i+1<<endl;
			return 0;
		}
		mark[A[i]]=1;
	}
	cout<<-1<<endl;
	return 0;
}
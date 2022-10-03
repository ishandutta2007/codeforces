#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010, MAX=15000000;

int n, k, g, cnt;
int x;
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x;
		if (x==1) ans=1;
	}
	if (ans==1) cout<<"HARD"<<endl;
	else cout<<"EASY"<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 20010;

int n, k;
vector<int> out;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	int nn=n;
	for (int i=2; i<=n; i++){
		if (n%i) continue ;
		out.push_back(i);
		n/=i;
		i--;
	}
	if (out.size()<k){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0; i<k-1; i++){
		cout<<out[i]<<' ';
		nn/=out[i];
	}
	cout<<nn<<endl;
	return 0;
}
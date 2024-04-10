#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000 * 1000 + 10;

int n, x, y, tmp;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n<3){
		cout<<"No"<<endl;
		return 0;
	}
	if (n%2){
		x=(n+1)/2;
		y=n;
	}
	else{
		x=n/2;
		y=n+1;
	}
	cout<<"Yes"<<endl;
	cout<<"1 "<<x<<endl;
	cout<<n-1<<' ';
	for (int i=1; i<=n; i++){
		if (i==x) continue ;
		cout<<i<<' ';
	}
	cout<<endl;
	
	return 0;
}
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

int n, ax, ay, bx, by, cx, cy;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>bx>>by>>ax>>ay>>cx>>cy;
	
	if ((ax<bx && bx<cx)||(cx<bx && bx<ax)||(ay<by && by<cy)||(cy<by && by<ay)){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}
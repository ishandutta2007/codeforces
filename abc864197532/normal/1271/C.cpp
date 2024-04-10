#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	int n,a,b;
	cin >> n >> a >> b;
	int direction[4]={0,0,0,0};
	fop (i,0,n) {
		int aa,bb;
		cin >> aa >> bb;
		if (aa < a) {
			direction[0]++;
		} if (aa > a) {
			direction[1]++;
		} if (bb < b) {
			direction[2]++;
		} if (bb > b){
			direction[3]++;
		}
	}
	int aa = max_element(direction, direction+4) - direction;
	cout << direction[aa] << endl;
	if (aa == 0) {
		cout << a-1 << ' ' << b << endl;
	}
	if (aa == 1) {
		cout << a+1 << ' ' << b << endl;
	}
	if (aa == 2) {
		cout << a << ' ' << b-1 << endl;
	}
	if (aa == 3) {
		cout << a << ' ' << b+1 << endl;
	}
}
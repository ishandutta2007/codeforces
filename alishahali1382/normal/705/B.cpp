#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int mod=1000 * 1000 * 1000 + 7;
const int MAXN=1010;

int n, a, s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a;
		s+=a%2-1;
		if (s%2) cout<<1<<endl;
		else cout<<2<<endl;
	}

	return 0;
}
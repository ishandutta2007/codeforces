#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1000 * 1000 + 10;

int n, m, ans;
int A[MAXN];

string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	while (n){
		ans++;
		n/=2;
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mnm = 0, mxm = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'L')
			mnm ++;
		else
			mxm ++;
	}
	cout << mxm + mnm + 1 << endl;
}
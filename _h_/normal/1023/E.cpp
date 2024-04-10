#include <bits/stdc++.h>
using namespace std;

int n;

bool ask(int r, int c, bool bo){
	if(bo) cout << "? " << r << ' ' << c << ' ' << n << ' ' << n << endl;
	else cout << "? " << 1 << ' ' << 1 << ' ' << r << ' ' << c << endl;
	string ans;
	cin >> ans;
	if(ans != "YES" && ans != "NO") exit(1);
	return ans=="YES";
}

int main(){

	cin >> n;

	string st, fn;

	for(int r = 1, c = 1; r+c < n+1;){
		if(ask(r, c+1, true)){
			++c;
			st.push_back('R');
		} else {
			++r;
			st.push_back('D');
		}
	}
	for(int r = n, c = n; r+c > n+1;){
		if(ask(r-1, c, false)){
			--r;
			fn.push_back('D');
		} else {
			--c;
			fn.push_back('R');
		}
	}

	string ans = "! ";
	for(int i = 0; i < n-1; ++i) ans.push_back(st[i]);
	for(int i = n-2; i >= 0; --i) ans.push_back(fn[i]);

	cout << ans << endl;

}
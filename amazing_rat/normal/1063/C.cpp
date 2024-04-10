#include <bits/stdc++.h>

typedef long long ll ;

using namespace std;

int n;
string s, first;

int main() {
	cin>>n;
	n--;
	cout << "0 1" << endl;
	
	fflush(stdout);
	
	cin >> first;
	
	ll l = 0, r = 1e9 ;
	while(n--){
		
		ll	mid = (l+r)/2;
		cout << mid << " 1" << endl;
		fflush(stdout);
		cin >> s;
		if(s[0]==first[0]){
			l = mid;
		}
		else r = mid;
	}
	cout << l << ' ' << 0 << ' ' << r << ' ' << 2 << endl ;
	fflush(stdout);
	return 0;
}
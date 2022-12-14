#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	bool found = 0;
	for (int i = 0; i < 5; i++){
		string t;
		cin >> t;
		if (t[0] == s[0] or t[1] == s[1])
			found = 1;
	}
	if (found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int pos(string s) {
	if(s == "monday") return 0;
	if(s == "tuesday") return 1;
	if(s == "wednesday") return 2;
	if(s == "thursday") return 3;
	if(s == "friday") return 4;
	if(s == "saturday") return 5;
	if(s == "sunday") return 6;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	int a = pos(s1), b = pos(s2);
	if((a+31)%7 == b || (a+30)%7 == b || (a+28)%7 == b)
		cout << "YES";
	else
		cout << "NO";
}
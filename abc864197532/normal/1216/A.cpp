#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	string s;
	cin >> n >> s;
	int a=0;
	fop (i,0,n/2) {
		if (s[2*i]==s[2*i+1]) {
			a++;
			s[2*i]='a'+'b'-s[2*i];
		}
	}
	cout << a << endl << s << endl;
	
}
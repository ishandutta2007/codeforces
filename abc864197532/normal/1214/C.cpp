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
	int tmp=0,m=0;
	fop (i,0,n) {
		if (s[i]=='(') tmp++;
		else tmp--;
		m=min(m,tmp);
	}
	if (m<-1 or tmp!=0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,a=0,b=0;
	cin >> n;
	string s1,s2;
	cin >> s1 >> s2;
	vector <int> n1,n2;
	fop (i,0,n) {
		if (s1[i]=='a' && s2[i]=='b') n1.pb(i+1);
		if (s1[i]=='b' && s2[i]=='a') n2.pb(i+1);
	}
	if ((n1.size()+n2.size())%2!=0) {
		cout << -1 << endl;
	} else {
		cout << (n1.size()+n2.size())/2+n1.size()%2 << endl;
		fop (i,0,n1.size()/2) {
			cout << n1[2*i] << ' ' << n1[2*i+1] << endl;
		} fop (i,0,n2.size()/2) {
			cout << n2[2*i] << ' ' << n2[2*i+1] << endl;
		}
		if (n1.size()%2==1) {
		    cout << n1[n1.size()-1] << ' ' << n1[n1.size()-1] << endl;
		    cout << n1[n1.size()-1] << ' ' << n2[n2.size()-1] << endl;
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int main () {
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	string s1,s2;
		cin >> n >> s1 >> s2;
		char a,b;
		bool is = true, iss=true;
		int c = 0;
    	fop (i,0,n) {
    		if (s1[i] != s2[i]) {
    			if (is) {
					b = s2[i];
	    			a = s1[i];
    				is=false;
				} else {
					if (c) {
						cout << "NO" << endl;
						iss=false;
						break;
					}
					if (s1[i] == a and s2[i] == b) {
						c = 1;
						is=true;
					} else {
						cout << "NO" << endl;
						iss=false;
						break;
					}
				}
			}
		}
		if (!iss) continue;
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
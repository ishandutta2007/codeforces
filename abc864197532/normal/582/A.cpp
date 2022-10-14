#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,tmp;
	cin >> n;
	map <int,int> m1;
	fop (i,0,n*n) {
	    cin >> tmp;
	    if (m1.count(tmp)) m1[tmp]++;
	    else m1[tmp] = 1;
	}
	vector <int> ans;
	for (auto a = m1.rbegin(); a != m1.rend(); ++a) {
	    while (a->second) {
	        ans.pb(a->first);
	        fop (i,0,ans.size()-1) {
	            m1[__gcd(ans[i], a->first)] -= 2;
	        }
	        a->second--;
	    }
	}
	fop (i,0,ans.size()) cout << ans[i] << ' ';
	cout << endl;
}
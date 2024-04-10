#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
vector <int> change(int n ,int k) {
	vector <int> ans;
	while (n) {
		ans.pb(n%3);
		n /= 3;
	}
	while (ans.size() < k) ans.pb(0);
	return ans;
}
 
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int p[n];
	p[0] = 1;
	fop (i,1,n) p[i] = p[i-1] * 3;
	int nums[n][3];
	fop (i,0,n) {
	    cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
	}
	map <tuple<int,int,int>, pii> m1;
	int k = n / 2;
	if (k == 0) {
	    if (nums[0][0] == nums[0][1]) cout << "LM" << endl;
	    else if (nums[0][1] == nums[0][2]) cout << "MW" << endl;
	    else if (nums[0][0] == nums[0][2]) cout << "LW" << endl;
	    else cout << "Impossible" << endl;
	    return 0;
	}
	fop (i,0,p[k]) {
		int a=0, b=0, c=0;
		vector <int> aa = change(i,k);
		fop (j,0,k) {
			if (aa[j] == 0) {
				a += nums[j][0];
				b += nums[j][1];
			}
			if (aa[j] == 1) {
				a += nums[j][0];
				c += nums[j][2];
			}
			if (aa[j] == 2) {
				b += nums[j][1];
				c += nums[j][2];
			}
		}
		int minn = min({a, b, c});
		a -= minn;
		b -= minn;
		c -= minn;
		tuple<int,int,int> tmp = make_tuple(a, b, c);
		if (m1.count(tmp)) {
			if (minn > m1[tmp].first) m1[tmp] = mp(minn, i);
		} else {
			m1[tmp] = mp(minn, i);
		}
	}
	int ans1;
	bool is = false;
	pii ans;
	fop (i,0,p[n-k]) {
		int a=0, b=0, c=0;
		vector <int> aa = change(i,n-k);
		fop (j,0,n-k) {
			if (aa[j] == 0) {
				a += nums[k+j][0];
				b += nums[k+j][1];
			}
			if (aa[j] == 1) {
				a += nums[k+j][0];
				c += nums[k+j][2];
			}
			if (aa[j] == 2) {
				b += nums[k+j][1];
				c += nums[k+j][2];
			}
		}
		int maxx = max({a, b, c});
		a = maxx - a;
		b = maxx - b;
		c = maxx - c;
		tuple<int,int,int> tmp = make_tuple(a, b, c);
		if (m1.count(tmp)) {
			if (!is) {
				is = true;
				ans1 = m1[tmp].first + maxx;
				ans = mp(m1[tmp].second, i);
			} else if (ans1 < m1[tmp].first + maxx) {
				ans1 = m1[tmp].first + maxx;
				ans = mp(m1[tmp].second, i);
			}
		}
	}
	if (!is) {
		cout << "Impossible" << endl;
		return 0;
	}
	int aa, bb;
	tie(aa, bb) = ans; 
	vector <int> aaa = change(aa, k), bbb = change(bb, n-k);
	fop (i,0,k) {
		if (aaa[i] == 0) cout << "LM" << endl;
		if (aaa[i] == 1) cout << "LW" << endl;
		if (aaa[i] == 2) cout << "MW" << endl;
	}
	fop (i,0,n-k) {
		if (bbb[i] == 0) cout << "LM" << endl;
		if (bbb[i] == 1) cout << "LW" << endl;
		if (bbb[i] == 2) cout << "MW" << endl;
	} 
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

bool bigger(tuple<int,int,int> a, tuple<int,int,int> b) {
	int c,d,e,f;
	tie(c,d,ignore)=a;
	tie(e,f,ignore)=b;
	if (c<e) return true;
	if (c==e and d<f) return true;
	return false;
}

int main () {
	int t,n;
	cin >> t;
	while (t--) {
		int x,y;
		cin >> n;
		tuple <int,int,int> nums[n];
		int m;
		bool is=false;
		int ans[n];
		fop (i,0,n) {
			cin >> x >> y;
			nums[i]=make_tuple(x,y,i);
		}
		sort(nums,nums+n,bigger);
		ans[0]=1;
		m=get<1>(nums[0]);
		fop (i,1,n) {
			if (is) {
				ans[i]=2;
			} else if (m<get<0>(nums[i])) {
				is=true;
				ans[i]=2;
			} else {
				ans[i]=1;
				m=max(m,get<1>(nums[i]));
			}
		}
		vector <tuple<int,int,int> > nn;
		fop (i,0,n) {
			nn.eb(get<2>(nums[i]),ans[i],0);
		}
		sort(nn.begin(),nn.end(),bigger);
		if (is) {
			fop (i,0,n) {
				cout << get<1>(nn[i]) << ' ';
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
}
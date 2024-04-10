#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

struct sol {
	sol() {}
	void solve() {
		int n;
		cin>>n;
		vi rank(n,1);
		int inv[n],cur;
		rep(i,n) {
			cin>>cur;
			--cur;
			inv[cur]=i;
		}
		multiset<int> st(all(rank));
		//db((st.size()));
		int q, tmp;
		rep(i,n) {
			int maxr = *(st.rbegin());
			q = inv[i];
			//db3(maxr, i, inv[i]);
			if(rank[q] == maxr) {
				rank[q] = -1;
				//db("yay");
				st.erase(st.find(maxr));
				if(q != n-1 && rank[q+1] != -1) {
					st.erase(st.find(rank[q+1]));
					rank[q+1] += maxr;
					st.insert(rank[q+1]);
				}
			} else {
				cout<<"No"<<endl;
				return;
			}
		}
		cout<<"Yes"<<endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--) {
    	sol s;
    	s.solve();
    }


}
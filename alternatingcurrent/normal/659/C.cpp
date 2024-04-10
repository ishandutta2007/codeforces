#pragma GCC optimize(2)
//Happy TLE and WA every day!
#include<bits/stdc++.h>
#define mp			make_pair
#define rep(i,n)	for(int i = 0; i < n; i++)
#define BINF		0x7fffffff
#define INF			0x3f3f3f3f
#define LINF		3223372036854775807
#define END(s)		{cout<<s; return 0;}
#define CON(s)		{cout<<s; continue;}
#define BRE(s)		{cout<<s; break;}
#define pb			push_back
//#define int			long long
#define All(a)		a.begin(), a.end()  //with A in CAPITAL!!!
#define sz(a)		(int)a.size()
#define F			first
#define S			second
//#define usingFiles
using namespace std;

const int rp = 666666;
const bool debug = 1;

map<int, bool> used;
vector<int> ans;

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	rep(i, n){
		int x;
		cin >> x;
		used[x] = true;
	}
	long long sum = 0;
	for(int i = 1; sum <= m; i++){
		if(!used[i] && sum + i <= m){
			sum += i;
			ans.pb(i);
		} else if(!used[i]){
			break;
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
	return 0;
}
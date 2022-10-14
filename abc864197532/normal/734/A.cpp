#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

int n;
vector <int> input;
vector <int> lis, now_lis;
vector <lli> ans, anss;
vector <deque <int>> dq;

void solve1_3 () {
	now_lis.resize(n);
	lis.pb(input[0]);
	now_lis[0] = 1;
	fop (i,1,n) {
		if (lis.back() <= input[i]) {
			lis.pb(input[i]);
			now_lis[i] = lis.size();
		} else {
			int id = upper_bound(all(lis), input[i]) - lis.begin();
			lis[id] = input[i];
			now_lis[i] = id + 1;
		}
	}
}

void solve2 () {
	dq.resize(lis.size() + 1, deque <int>());
	ans.resize(lis.size() + 1, 0);
	anss.resize(n, 0);
	fop (i,0,n) {
		if (now_lis[i] == 1) anss[i] = 1;
		else {
			int a = now_lis[i] - 1;
			while (dq[a].size() and input[dq[a].front()] > input[i]) {
				(ans[a] += mod - anss[dq[a].front()]) %= mod;
				dq[a].pop_front();
			}
			anss[i] = ans[a];
		}
		int a = now_lis[i];
		(ans[a] += anss[i]) %= mod;
		dq[a].push_back(i);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> n >> s;
	int a = count(all(s), 'A');
	int b = count(all(s), 'D');
	if (a > b) cout << "Anton\n";
	else if (a < b) cout << "Danik\n";
	else cout << "Friendship\n";
}
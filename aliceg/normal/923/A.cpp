#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define OP1 freopen("file.in.txt", "r", stdin)
#define OP2 freopen("file.out.txt", "w", stdout)
#define INF 1000000007
#define ll long long
#define ull unsigned long long
#define LINF ((ll)INF * (ll)INF)
#define db double
#define vi vector <int>
#define vf vector <float>
#define vdb vector <db>
#define vstr vector <string>
#define vll vector <ll>
#define forin(i, k) for (int i = 0; i < k; i++)
#define fordown(i, n) for (int i = n; i >= 0; i--)
#define forto(i, k) for (int i = 1; i <= k; i++)
#define forlong(i, k) for (ll i = 0; i < k; i++)
#define formod(i, k, m) for (int i = m; i < k; i++)
#define fi(n) forin(i, n)
#define fj(n) forin(j, n)
#define fii(n) forto(i, n)
#define fjj(n) forto(j, n)
#define fid(n) fordown(i, n)
#define fjd(n) fordown(j, n)
#define si set <int>
#define sf set <float>
#define sdb set <db>
#define sll set <ll>
#define sstr set <string>
#define mi map <int, int>
#define sch set <char>
#define vch vector <char>
#define m_str map <int, string>
#define v_v(type) vector <type> v;
#define s_s(type) set <type> s;
#define m_m(type, t1) map <type, t1> m;
#define pii pair <int, int>
#define viv vector <int> v
#define sis set <int> s
#define mim map <int, int> m
#define qiq queue <int> q
#define diq deque <int> q
#define riter(v) for (auto it = v.rbegin(); it != v.rend(); it++)
#define iter(v) for (auto it = v.begin(); it != v.end(); it++)
#define siter(v) for (auto sit = v.begin(); sit != v.end(); sit++)
#define rsiter(v) for (auto sit = v.rbegin(); sit != v.rend(); sit++)
#define sriter(v) rsiter(v)
#define cout_v(v, symb) iter(v) cout << *it << symb;
#define base_1 int n; cin >> n
#define base_2 int n, k; cin >> n >> k
#define base_3 int n, k, d; cin >> n >> k >> d
#define base_n int n; cin >> n
#define base_k int k; cin >> k
#define base_d int d; cin >> d
#define b_n base_n
#define b_k base_k
#define b_d base_d
#define b_tmp int tmp; cin >> tmp
#define mp make_pair
#define OPcIn cin.tie(NULL)
#define SWT OPcIn; ios_base::sync_with_stdio(false)
///#pragma optimize ("gtsy", on)
#pragma comment(linker, "/STACK:16777216")
#define graph vector <vector <int>>
#define pb emplace_back
#define F first
#define S second
#define vvi graph
#define vvll vector <vector <ll>>
#define vvf vector <vector <float>>
#define vvdb vector <vector <db>>
#define vvstr vector <vector <string>>
#define vpii vector <pii>
#define vvpii vector <vpii>
#define add_v(i, type) type TMP; cin >> TMP; i.pb(TMP)
#define add_s(i, type) type TMP; cin >> TMP; i.insert(TMP)
#define add_vp(i, t1, t2) type t1, t2; cin >> t1 >> t2; i.pb(mp(t1, t2))
#define add_sp(i, t1, t2) type t1, t2; cin >> t1 >> t2; i.insert(mp(t1, t2))
//#define endl '\n' 
using namespace std;
vector <bool> erath(1000001, true);
int main() {
	SWT;
#ifdef Kvas
	OP1;
	OP2;
#endif
	erath[0] = false;
	erath[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (erath[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				erath[j] = false;
			}
		}
	}
	b_n;
	int N = n;
	int mx = 0;
	fi(n) {
		if (erath[i]) {
			if (N % i == 0) {
				N /= i;
				mx = max(mx, i);
				i--;
			}
		}
	}
	int mn = INF;
	int n_mx = n;
	n = n - (mx - 1);
	fi(n_mx) {
		if (erath[i]) {
			int tmp = n / i;
			if (n % i) {
				tmp++;
			}
			if (tmp * i <= n_mx && tmp * i - i + 1 >= 3) {
				mn = min(mn, tmp * i - i + 1);
			}

		}
	}
	cout << mn;
	return 0;
}
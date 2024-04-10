// Implementation practice (Have seen the editorial)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef set<int> si;
typedef priority_queue<int> pqi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define loop(i, a) for (int i = 0; i < (a); i++)
#define loop1(i, a) for (int i = 1; i <= (a); i++)
#define loopr(i, a, b) for (int i = (a); i <= (b); i++)
#define dloop(i, a) for (int i = (a) - 1; i >= 0; i--)
#define dloopr(i, b, a) for (int i = (b); i >= (a); i--)
#define tr(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define vpresent(container, element) (find(container.being(), container.end() ,element) != container.end())
#define show(a) cout << a << "\n"
#define showloop(a, len) for (int i = 0; i < len; i++) cout << a[i] << "\n"
#define debug(a) cout << #a << ": " << (a) << "\n"
#define mem(x, val) memset((x), (val), sizeof(x));
#define sz(x) ((int)x.size())
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
const int MOD = 1000000007;
const double PI = acos(-1);

int main() {
	/*freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);*/

	int n; cin >> n;
	int a[n]; loop(i, n) cin >> a[i];
	int diff = a[1] - a[0];
	loop1(i, n-1) {
		if (a[i] - a[i - 1] != diff) {
			show(a[n-1]);
			return 0;
		}
	}

	show(a[n-1] + diff);

	return 0;
}
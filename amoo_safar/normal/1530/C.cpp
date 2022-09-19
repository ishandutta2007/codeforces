// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N], b[N];
int pa[N], pb[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n, m;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> b[i];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		sort(a, a + n);
		sort(b, b + n);
		reverse(a, a + n);
		reverse(b, b + n);
		for(int i = 1; i <= n; i++)
			pa[i] = pa[i - 1] + a[i - 1];
		for(int i = 1; i <= n; i++)
			pb[i] = pb[i - 1] + b[i - 1];		
		for(int i = 0; i < 4 * n; i++){
			m = n + i;
			int c = m - (m / 4);
			int A = 100 * min(c, i) + pb[c - min(c, i)];
			int B = pa[min(c, n)];
			if(A >= B){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
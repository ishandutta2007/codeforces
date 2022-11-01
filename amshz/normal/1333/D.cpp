# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 3e6 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, k, ptr, ted, p;
vector <int> vec[xn];
string a, b;

int main(){
	InTheNameOfGod;
	
	cin >> n >> k >> a;
	while (ptr == 0 || vec[ptr - 1].size()){
		b = "";
		for (int i = 0; i < n; i ++){
			if (i && a[i] == 'L' && a[i - 1] == 'R') continue;
			if (a[i] == 'L'){
				b += 'L';
				continue;
			}
			else if (i < n - 1 && a[i + 1] == 'L'){
				b += "LR";
				ted ++;
				vec[ptr].push_back(i + 1);
			}
			else b += 'R';
		}
		ptr ++;
		a = b;
	}
	ptr --;
	if (ptr  > k){
		cout << -1 << endl;
		return 0;
	}
	if (ted < k){
		cout << -1 << endl;
		return 0;
	}
	ted = ptr;
	for (int i = 0; i < ptr; i ++){
		while (ted < k && vec[i].size() > 1){
			cout << 1 << sep << vec[i].back() << endl;
			vec[i].pop_back();
			ted ++;
		}
		cout << vec[i].size() << sep;
		for (int x : vec[i]) cout << x << sep;
		cout << endl;
	}
	
	
	return 0;
}
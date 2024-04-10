#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".IN", "r", stdin); freopen(x ".OUT", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef vector<int>::iterator vit;
typedef pair<ld, int> li;
const ld E = 1e-8;
typedef unsigned short int usi;

#ifdef LOCAL
const int MAX = 1e4;
#else
const int MAX = 3e4 + 1;
#endif

char get_not(char a, char b){
	return (a != 'a' && b != 'a' ? 'a' : a != 'b' && b != 'b' ? 'b' : 'c');
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	string a, b;
	cin >> a >> b;
	string s = a;
	int diff = 0;
	if(m > n){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			s[i] = a[i];
		}else{
			s[i] = ' ';
			diff++;
		}
	}
	if(m * 2 < diff){
		cout << -1;
		return 0;
	}
	int k1 = m, k2 = m;

	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			if(max(k1, k2) == 0){
				cout << -1;
				return 0;
			}
			if(k1 >= k2){
				k1--;
				s[i] = b[i];
			}else{
				k2--;
				s[i] = a[i];
			}
			//cout << k1 << " " << k2 << endl;
		}
	}

	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			if(s[i] == b[i] && k2 > 0){
				s[i] = get_not(a[i], b[i]);
				k2--;
			}else if(s[i] == a[i] && k1 > 0){
				s[i] = get_not(a[i], b[i]);
				k1--;
			}
		}
	}

	for(int i = 0; i < n; i++)
		if(a[i] == b[i] && k1 > 0){
			s[i] = get_not(a[i], b[i]);
			k1--;
		}

	cout << s << endl;

}
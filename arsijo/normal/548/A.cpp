#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;
const int IM = 2e9;
const ld E = 1e-9;
const int MAX = 30000;
int ar[MAX], pos = 0, t = 0;

bool isPalidrom(string s){
	for(int i = 0; i < (int) s.length() / 2; i++)
		if(s[i] != s[(int) s.length() - 1 - i])
			return false;
	return true;
}

void goHome(){
	cout << "NO";
	exit(0);
}

int main() {

	string s;
	cin >> s;

	int n;
	cin >> n;

	if(s.length() % n != 0)
		goHome();

	int a = s.length() / n;
	for(int i = 0; i < (int) s.length(); i += a)
		if(!isPalidrom(s.substr(i, a)))
			goHome();

	cout << "YES";

}
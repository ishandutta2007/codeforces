#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define MAX 300001
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;

int main() {

	int n;
	cin >> n;

	if(n <= 2){
		cout << "1\n1";
	}else if (n == 3){
		cout << "2\n1 3";
	}else if(n == 4){
		cout << "4\n3 1 4 2";
	}else{
		int r = (n + 1) / 2;
		cout << n << endl;
		if(n % 2 == 1)
			cout << n / 2 + 1 << " ";
		for(int i = 1; i <= n / 2; i++)
			cout << i << " " << i + r << " ";
	}

}
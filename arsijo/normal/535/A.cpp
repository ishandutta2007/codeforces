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

	string ar[20] = { "zero", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
			"fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
			"nineteen" };

	int n;
	cin >> n;

	string a[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	if(n < 20){
		cout << ar[n];
	}else{
		cout << a[n / 10];
		if(n % 10 != 0)
			cout << "-" << ar[n % 10];
	}

}
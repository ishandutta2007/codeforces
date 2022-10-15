#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator si;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 1250000;
///#define DEBUG
#else
const ll MAX = 1250000;
#endif

bool pr[MAX];

void eratosfen(){
	ms(pr);
	pr[0] = pr[1] = true;
	int g = sqrt(MAX);
	for(int i = 2; i <= g; i++){
		if(pr[i])
			continue;
		for(int j = i * i; j < MAX; j += i)
			pr[j] = true;
	}
}

bool prime(int a){
	return !pr[a];
}

vector<int> vec;

void add(){
	bool g = true;
	for(int i = 0; i < (int) vec.size() && g; i++){
		if(++vec[i] == 10){
			vec[i] = 0;
		}else{
			g = false;
		}
	}
	if(g){
		for(int i = 0; i < (int) vec.size(); i++)
			vec[i] = 0;
		vec.push_back(1);
	}
}

bool primes(int a){
	for(int i = 2; i <= sqrt(a); i++)
		if(a % i == 0)
			return false;
	return a != 1;
}

int palidrom(int a){
	int g = (int) vec.size();
	for(int i = 0; i < g / 2; i++)
		if(vec[i] != vec[g - i - 1])
			return false;
	return true;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	ll e = 1180351 + 10;

	ll p, q;
	cin >> p >> q;

	eratosfen();
	vec.push_back(0);

	int ans = -1;

	ll a = 0, b = 0;

	for(int i = 1; i < MAX; i++){
		if(prime(i))
			a++;
		add();
		if(palidrom(i))
			b++;
		if(a * q <= b * p)
			ans = i;
	}

	if(ans > e || ans == -1){
		cout << "Palindromic tree is better than splay tree";
	}else{
		cout << ans;
	}

}
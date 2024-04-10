#include<bits/stdc++.h>
#define pb push_back
const int inf = 1e9 + 100;
using namespace std;
vector<int> a;


void func(long long n) {
	a.clear();
	int cnt = 2;
	while(n > 0){
		a.pb(n%cnt);
		n /= cnt;
		cnt++;
	}
}

long long fact[30];

void solve(){
	long long n;
	cin >> n;
	func(n);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	long long ans = 1;
	vector<int> b;
	bool zero = false;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == 0){zero = true; break;}
		int x = a.size() - a[i] + 1;
		ans *= (x-i);
		b.pb(x-i);
	}
	int last = a[0];
	int cnt = 1;
	long long facts = 1;
	bool check = false;
	for(int i = 1; i < a.size(); ++i){
		if(a[i] != last){
			facts *= fact[cnt];
			cnt = 1;
			last = a[i];
		} else cnt++;
	}
	if(a[a.size()-1] != 0) facts *= fact[cnt];
	ans /= facts;
	if(!zero) {
		cout << ans - 1 << endl;
		return;
	}
	long long res = 1;
	for(int i = 0; i < b.size(); ++i){
		res *= b[i] - 1;
	}
	res/=facts;
	cout << (ans - res) - 1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	#ifdef LOCAL_DEFINE
	#endif
	long long q = 1;
	for(int i = 0; i < 20; ++i){
		fact[i] = q;
		q *= i+1;
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
		solve();

	return 0;
}
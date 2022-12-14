/**
 *    author:  Atreus
 *    created: 03.02.2019 12:55
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int maxn = 1e6 + 10;

vector<int> prm;
void tajzie(int x){
	for (int i = 2; 1ll * i * i <= x; i++){
		if (x % i == 0){
			prm.push_back(i);
			while (x % i == 0){
				x /= i;
			}
		}
	}
	if (x > 1)
		prm.push_back(x);
}

short val[maxn];
int nex[maxn];

ll findprm(int n, ll a, ll b){
	ll ret = inf;
	ll par = 0;
	for (int i = 1; i <= n; i++){	
		if (val[i] == -1)
			break;
		par += 1ll * val[i] * b;
		ret = min(ret, par + 1ll * (n - i) * a);
	}
	par = 0;
	for (int i = n; i >= 1; i--){
		if (val[i] == -1)
			break;
		par += val[i] * b;
		ret = min(ret, par + 1ll * (i - 1) * a);
	}
	if (val[n] == -1)
		return ret;
	int ptr = n;
	ll x = val[n] * b - a;
	par = 0;
	for (int i = n; i >= 1; i--){
		if (val[i] == -1)
			break;
		par += val[i] * b - a;
		if (par < x){
			nex[i] = ptr;
			ptr = i;
			x = par;
		}
	}
	ll Suf = 0;
	for (int i = n; i >= ptr; i--)
		Suf += val[i] * b;
	ll Pre = 0;
	for (int i = 1; i < n; i++){
		if (val[i] == -1)
			break;
		if (ptr == i){
			int tmp = nex[ptr];
			while (ptr < tmp){
				Suf -= val[ptr] * b;
				ptr ++;
			}
		}
		Pre += val[i] * b;
		ret = min(ret, Pre + Suf + 1ll * (ptr - i - 1) * a);
	}
	return ret;
}

int a[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	int n, x, b;
	cin >> n >> x >> b;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1)
		return cout << 0 << endl, 0;
	for (int i = 1; i <= n; i += n - 1){
		for (int j = -1; j <= 1; j++){
			tajzie(a[i] + j);
		}
	}
	sort(prm.begin(), prm.end());
	prm.resize(unique(prm.begin(), prm.end()) - prm.begin());
	ll answer = inf;
	for (int i = 0; i < int(prm.size()); i++){
		for (int j = 1; j <= n; j++){
			if (a[j] % prm[i] == 0)
				val[j] = 0;
			else if (((a[j] + 1) % prm[i] == 0) or (a[j] - 1) % prm[i] == 0)
				val[j] = 1;
			else
				val[j] = -1;
		}
		answer = min(answer, findprm(n, x, b));
	}
	cout << answer << endl;
}
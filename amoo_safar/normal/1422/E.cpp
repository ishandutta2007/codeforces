// I'll Crush you !
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

vector<int> V;

int flg = 1; // 1 -> x   0 -> AAx 

void Add(int y){
	V.pb(y);
	int m = V.size();
	if(y != V[m - 3]){
		if(y < V[m - 3]) flg = 0;
		else flg = 1;
	}
}

ll ans[N];
str S[N];

void Calc(int i){
	if(ans[i] <= 10){
		S[i] = "";
		for(int j = 0; j < ans[i]; j++)
			S[i] += (char)('a' + V[V.size() - 1 - j]);
	} else {
		for(int j = 0; j < 5; j++)
			S[i] += (char)('a' + V[V.size() - 1 - j]);
		S[i] += "...";
		for(int j = ans[i] - 2; j< ans[i]; j++)
			S[i] += (char)('a' + V[V.size() - 1 - j]);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	V.pb(-2); V.pb(-2); V.pb(-2);
	str s;
	cin >> s;
	ll n = s.size();

	ans[n - 1] = 1;
	S[n - 1] += s[n - 1];
	
	int la = (s[n - 1] - 'a'), laa = -1;

	for(int i = n - 2; i >= 0; i--){
		int nw = s[i] - 'a';
		if(s[i] != s[i + 1]){
			//swap(la, laa);
			if(la != -1)
				Add(la);
			laa = -1;
			la = nw;
		} else {
			assert(la == -1 || laa == -1);
			

			if(laa == -1){
				int nw2 = la;
				int fl = flg;
				if(nw2 > V[V.size() - 2]) fl = 1;
				if(nw2 < V[V.size() - 2]) fl = 0;
				
				if(nw > V[V.size() - 1]) fl = 1;
				if(nw < V[V.size() - 1]) fl = 0;
				//debug(i);
				//debug(fl);
				if(fl){
					swap(la, laa);
					//cerr << V.size() << la << '\n';
				} else {
					Add(la);
					la = nw;
					laa = -1;
				}
			} else {
				if(nw <= laa){
					la = nw;
					laa = -1;
				} else {
					swap(la, laa);
				}	
			}
		}
		if(la != -1) V.pb(la);
		ans[i] = (V.size() - 3);
		Calc(i);
		if(la != -1) V.pop_back();
		//cerr << V.size() << '\n';
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ' << S[i] << '\n';
	return 0;
}
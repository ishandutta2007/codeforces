#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 11
#define INF 101111111111111
using namespace std;
map<string, ll> ms;
string a[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		ms.clear();
		for(ll i=0;i<n;i++){
			string aa;
			cin >> aa;
			ms[aa]++;
			a[i] = aa;
		}
		ll chd = 0;
		for(ll i=0;i<n;i++){
			if(ms[a[i]] > 1){
				string t = a[i];
				string ort = t;
				for(ll j = 0;j<4;j++){
					bool brk = false;
					char orig = t[j];
					for(char l = '0';l<='9';l++){
						t[j] = l;
						if(ms[t] == 0){
							a[i] = t;
							ms[t] = 1;
							chd++;
							brk = true;
							break;
						}
					}
					if(brk) break;
					else t[j] = orig;
				}
				ms[ort]--;
			}
		}
		cout << chd << endl;
		for(ll i =0;i<n;i++) cout << a[i] << endl;
	}
}
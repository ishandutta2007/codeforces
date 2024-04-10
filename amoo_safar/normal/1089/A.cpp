#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 200 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


pll par[4][4][Maxn + 30][Maxn + 30];
vector<pll> ans, AA;
ll W1, W2;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	par[0][0][0][0] = {-1, -1};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < Maxn; k++) for(int k2 = 0; k2 < Maxn; k2 ++){
				if(par[i][j][k][k2] == pll(0, 0)) continue;
				
				if(i < 2){
					for(int x = 0; x < 24; x++){
						par[i + 1][j][k + 25][k2 + x] = {25, x};
					}
					for(int x = 24; x < Maxn; x ++){
						if(k2 + x + 2 > Maxn + 3) continue;
						if(k + x + 2 > Maxn + 3) continue;
						
						par[i + 1][j][k + x + 2][k2 + x] = {x + 2, x};
					}
				}
				if(j < 2){
					for(int x = 0; x < 24; x++){
						par[i][j + 1][k + x][k2 + 25] = {x, 25};
					}
					
					for(int x = 24; x < Maxn; x ++){
						if(k2 + x + 2 > Maxn + 3) continue;
						if(k + x + 2 > Maxn + 3) continue;
						
						par[i][j + 1][k + x][k2 + x + 2] = {x, x + 2};
					}
				}
			}
		}
	}
	
	//cout << "!!!" << par[2][0][50][0].F << '\n';
	ll m;
	cin >> m;
	while(m--){
		ans.clear();
		ll a, b, A, B;
		cin >> a >> b;
		W1 = -1000; W2=  1000;
		
		for(int i = 2; i >= 0; i--){
			for(int j = 0; j < 3; j++){
				ll wp;
				if(i + j == 4) wp = 15;
				else wp = 25;
				for(int k = 0; k < Maxn; k++) {
				ll k2 =-1;
				A = a-k;
				if(A > wp) k2 = b - (A - 2);
				if(A < wp - 1) k2 = b - (wp);
				if(k2 != -1){
					if(k2 < -1) continue; 
					if(par[i][j][k][k2] == pll(0, 0)) continue;
					//if(ans.size()) continue;
					
					
					A = a - k;
					B = b - k2;
					if(min(A, B) < 0) continue;
					ll D = abs(A - B);
					if(abs(A - B) < 2) continue;
				
						
					if(max(A, B) < wp) continue;
					
					if(D == 2){
						if(A > B && i == 2){
							if(i-j+1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i + 1;
							W2 = j;
							
						}
						if(B > A && j == 2){
							if(i-j-1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i;
							W2 = j + 1;
							
						}
						
					} else {
						if(A == wp && A > B && i == 2){
							if(i-j+1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i + 1;
							W2 = j;
							
						}
						if(B == wp && B > A && j == 2){
							if(i-j-1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i;
							W2 = j + 1;
						}
					}
				
				}
				if(A == wp || A == wp - 1)
				for(k2 = 0; k2 < Maxn; k2 ++){
					
					if(par[i][j][k][k2] == pll(0, 0)) continue;
					//if(ans.size()) continue;
					
					
					A = a - k;
					B = b - k2;
					if(min(A, B) < 0) continue;
					ll D = abs(A - B);
					if(abs(A - B) < 2) continue;
				
						
					if(max(A, B) < wp) continue;
					
					if(D == 2){
						if(A > B && i == 2){
							if(i-j+1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i + 1;
							W2 = j;
							
						}
						if(B > A && j == 2){
							if(i-j-1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i;
							W2 = j + 1;
							
						}
						
					} else {
						if(A == wp && A > B && i == 2){
							if(i-j+1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i + 1;
							W2 = j;
							
						}
						if(B == wp && B > A && j == 2){
							if(i-j-1 > W1- W2) ans.clear();
							else continue;
							ll I = i, J = j;
							ll S1 = k, S2 = k2;
							while(I + J){
								ans.pb(par[I][J][S1][S2]);
								S1 -= ans.back().F;
								S2 -= ans.back().S;
								if(ans.back().F < ans.back().S) J--;
								else I --;
							}
							ans.pb({A, B});
							W1 = i;
							W2 = j + 1;
						}
					}
				
				}
			}
			}
		}	
		//cout << "KIF" << endl;
		if(ans.size() == 0) cout << "Impossible\n";
		else{
			cout << W1 << ":" << W2 <<'\n';
			for(auto x : ans) cout << x.F << ":" << x.S << ' '; cout << '\n';
			//cout << flush;
		}
	}
	
	return 0;
}
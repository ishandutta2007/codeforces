#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll Mod = 998244353;
void update(ll &a, ll b){
	a += b;
	if(a >= Mod)
		a -= Mod;
}

string s;
int n;
ll dp[200200][4][3][8];

int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	n = (int)s.size();
	dp[0][0][1][0] = 1;
	rep(i, n){
		rep(op1, 4) rep(op2, 3) rep(op3, 8){
			if(!dp[i][op1][op2][op3])
				continue;
//			cout << i << " " << op1 << " " << op2 << " " << op3 << ": " << dp[i][op1][op2][op3] << endl;
			rep(tp, 8){
				int ca = tp & 1, cb = (tp >> 1) & 1, cc = (tp >> 2) & 1;
//				cout << ca << " " << cb << " " << cc << endl;
				if(!(op3 & 1) && ca > s[i] - '0')
					continue;
				if(!(op3 & 2) && cb > s[i] - '0')
					continue;
				if(!(op3 & 4) && cc > s[i] - '0')
					continue;
//				cout << ca << " " << cb << " " << cc << endl;
				if(!(op1 & 1) && (ca ^ cb) < (cb ^ cc))
					continue;
				if(!(op1 & 2) && (cb ^ cc) < (cc ^ ca))
					continue;
//				cout << ca << " " << cb << " " << cc << endl;
				int na, ns;
				if(op2 == 0)
					na = 1, ns = 0;
				if(op2 == 1)
					na = ns = 0;
				if(op2 == 2)
					na = 0, ns = 1;
				na <<= 1, ns <<= 1;
				na += ca ^ cb, ns += (cb ^ cc) + (cc ^ ca);
				if(na > ns + 1)
					continue;
//				cout << ca << " " << cb << " " << cc << endl;
				int nop3 = op3;
				nop3 |= ((tp & 1) < s[i] - '0') + (((tp & 2) < s[i] - '0') << 1) + (((tp & 4) < s[i] - '0') << 2);
				int nop2;
				if(na == ns + 1)
					nop2 = 0;
				if(na == ns)
					nop2 = 1;
				if(na < ns)
					nop2 = 2;
				int nop1 = op1;
				nop1 |= (((ca ^ cb) > (cb ^ cc))) + (((cb ^ cc) > (cc ^ ca)) << 1);
//				cout << nop1 << " " << nop2 << " " << nop3 << endl;
				update(dp[i + 1][nop1][nop2][nop3], dp[i][op1][op2][op3]);
			}
		}
	}
//	int i = n;
//		rep(op1, 4) rep(op2, 3) rep(op3, 8){
//			if(!dp[i][op1][op2][op3])
//				continue;
//			cout << i << " " << op1 << " " << op2 << " " << op3 << ": " << dp[i][op1][op2][op3] << endl;
//		}
	ll sum = 0;
	rep(op1, 4) rep(op3, 8)
		update(sum, dp[n][op1][2][op3]);
	cout << (sum * 6ll) % Mod << endl;
	return 0;
}
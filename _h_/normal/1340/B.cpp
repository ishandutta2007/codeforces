#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

string ds[10] = {
"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

typedef bitset<2048> bs;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vector<string> cur(n);
	trav(s, cur) cin >> s;

	vi cnt(n);
	rep(i,0,n) cnt[i] = count(all(cur[i]), '1');

	vi dcnt(10);
	rep(i,0,10) dcnt[i] = count(all(ds[i]), '1');

	vector<vi> dif(n, vi(10));
	rep(i,0,n) rep(d,0,10){
		rep(t,0,7) if(cur[i][t] > ds[d][t]){
			dif[i][d] = -1;
			goto foo;
		}
		dif[i][d] = dcnt[d] - cnt[i];
		foo: ;
	}
	
	vector<bs> pos(n+1);
	
	pos[n].set(0);
	rrep(i,0,n) rep(d,0,10) if(dif[i][d] >= 0){
		pos[i] |= pos[i+1] << dif[i][d];
	}	

	if(!pos[0][k]){
		cout << -1 << endl;
		return 0;
	}

	string ans;
	rep(i,0,n){
		rrep(d,0,10) if(dif[i][d] >= 0){
			if(dif[i][d] <= k && pos[i+1][k - dif[i][d]]){
				ans.push_back(d + '0');
				k -= dif[i][d];
				break;
			}
		}
	}
	cout << ans << endl;
}
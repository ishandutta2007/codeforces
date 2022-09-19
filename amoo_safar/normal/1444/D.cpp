// nemibinam invara kasi mesl khodemono !
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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

bitset<500010> H, V, tmp;
int ph[N], pv[N];
int h, v, l[N], p[N];

int mk[N], mk2[N];

void Main(){
	memset(mk, 0, sizeof mk);
	memset(mk2, 0, sizeof mk2);

	H = 0;
	V = 0;
	cin >> h;
	H[0] = 1;
	int sl = 0;
	for(int i = 0; i < h; i++){
		cin >> l[i];
		sl += l[i];
		tmp = H;
		H |= H << l[i];
		tmp ^= H;
		for(int bt = tmp._Find_first(); bt < (int)tmp.size(); bt = tmp._Find_next(bt)){
			ph[bt] = i;
		}
	}
	cin >> v;
	int sp = 0;
	V[0] = 1;
	for(int i = 0; i < v; i++){
		cin >> p[i];
		sp += p[i];
		tmp = V;
		V |= V << p[i];
		tmp ^= V;
		for(int bt = tmp._Find_first(); bt < (int)tmp.size(); bt = tmp._Find_next(bt)){
			pv[bt] = i;
		}
	}


	if((h != v) || (sl & 1) || (sp & 1)){
		cout << "No\n";
		return ;
	}

	if((H[sl/2] == 0) || (V[sp/2] == 0)){
		cout << "No\n";
		return ;
	}
	vector<int> oh(h);
	iota(all(oh), 0);
	int cnt=0;
	for(int nw = sl / 2; nw > 0;){
		mk[ph[nw]] = 1;
		nw -= l[ph[nw]];
		cnt ++;
	}
	if(cnt + cnt < h){
		for(int i = 0; i < h; i++) mk[i]^=1;
	}
	sort(all(oh), [&](int i, int j){
		if(mk[i] != mk[j]) return mk[i] < mk[j];
		return l[i] > l[j];
	});

	vector<int> ov(h);
	iota(all(ov), 0);
	cnt = 0;
	for(int nw = sp / 2; nw > 0;){
		mk2[pv[nw]] = 1;
		//debug(p[pv[nw]]);
		nw -= p[pv[nw]];
		cnt ++;
	}

	if(cnt + cnt > h){
		for(int i = 0; i < h; i++) mk2[i]^=1;
	}
	sort(all(ov), [&](int i, int j){
		if(mk2[i] != mk2[j]) return mk2[i] < mk2[j];
		return p[i] < p[j];
	});

	//debug(sp);
	ll X = 0, Y= 0 ;
	cout << "Yes\n";
	for(int i = 0; i < h; i++){
		if(mk[oh[i]]) X -= l[oh[i]]; 
		else X += l[oh[i]];
		cout << X << ' ' << Y << '\n';
		if(mk2[ov[i]]) Y -= p[ov[i]]; 
		else Y += p[ov[i]];
		cout << X << ' ' << Y << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T = 0;
	cin >> T;
	while(T --) Main();
	return 0;
}
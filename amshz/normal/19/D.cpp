# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 5e5 + 10;
const int xm = 2e5 + 10;
const int SQ = 500;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, Max[xn], Mx[xn], S, Tab[xn];
set <int> st[xn];
pair <string, pii> Q[xn];
unordered_map <int, int> mp;
vector <int> Compress;


void Update(int x, int y, bool f){
	if (f) st[x].insert(y);
	else st[x].erase(y);
	if (st[x].size()) Max[x] = *prev(st[x].end());
	else Max[x] = -1;
	Mx[x / SQ] = -1;
	for (int i = x - x % SQ; i < x - x % SQ + SQ; i ++)
		Mx[x / SQ] = max(Mx[x / SQ], Max[i]);
}

int Find(int ind, int y){
	for (int i = ind * SQ; i < ind * SQ + SQ; i ++)
		if (Max[i] > y) return i;
}

void Get(int x, int y){
	int find = -1;
	for (int i = x + 1; i <= 2e5;){
		if (i % SQ == 0){
			if (Mx[i / SQ] > y){
				find = Find(i / SQ, y);
				break;
			}
			i += SQ;
			continue;
		}
		if (Max[i] > y){
			find = i;
			break;
		}
		i ++;
		
	}
	if (find == -1){
		cout << -1 << endl;
		return;
	}
	cout << Tab[find] << sep << *st[find].upper_bound(y) << endl;
}

void Build(){
	for (int i = 0; i <= 5e5; i ++) Max[i] = -1, Mx[i] = -1;
	for (int i = 0; i < n; i ++) Compress.push_back(Q[i].second.F);
	sort(Compress.begin(), Compress.end());
	for (int i = 0; i < Compress.size(); i ++){
		if (i && Compress[i] == Compress[i - 1]) continue;
		Tab[S] = Compress[i];
		mp[Compress[i]] = S;
		S ++;
	}
	for (int i = 0; i < n; i ++)
		Q[i].second.F = mp[Q[i].second.F];
}

 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> Q[i].first >> Q[i].second.F >> Q[i].second.S;
	
	Build();
	
	for (int i = 0; i < n; i ++){
		if (Q[i].first == "add") Update(Q[i].second.F, Q[i].second.S, 1);
		else if (Q[i].first == "remove") Update(Q[i].second.F, Q[i].second.S, 0);
		else Get(Q[i].second.F, Q[i].second.S);
	}
	
	
	return 0;
}
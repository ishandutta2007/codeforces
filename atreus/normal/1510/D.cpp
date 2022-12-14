#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

int cnt[10];
vector<int> v[10];
vector<ld> sufz[10];
vector<int> sufm[10];
int wanted_d;

int not_choose[10];
int bst_choose[10];
ld bst = 1e100;
bool an = false;

void go(int pos = 0, ld zr = 1, int md = 1){
	if(pos == 10){
		if(md == wanted_d && bst > zr){
			bool some = 0;
			for(int i = 0; i < 10; i++)
				some|= not_choose[i] < cnt[i];
			if(!some)
				return;
			an = true;
			bst = zr;
			memcpy(bst_choose, not_choose, sizeof bst_choose);
		}
		return;
	}
	for(int i = 0; i < min(4, cnt[pos]+1); i++){
		not_choose[pos] = i;
		go(pos+1, zr * sufz[pos][i], md * sufm[pos][cnt[pos] - i] % 10);
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n >> wanted_d;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v[x%10].push_back(x);
		cnt[x%10]++;
	}
	if(wanted_d % 2 != 0){
		for(int i = 0; i < 10; i+= 2)
			v[i].clear(), cnt[i] = 0;
	}
	if(wanted_d % 5 != 0){
		for(int i = 0; i < 10; i+= 5)
			v[i].clear(), cnt[i] = 0;
	}
	for(int i = 0; i < 10; i++){
		sort(v[i].begin(), v[i].end());
		sufz[i].push_back(1);
		for(int x : v[i]){
			sufz[i].push_back(sufz[i].back() * x);
		}
		reverse(v[i].begin(), v[i].end());
		sufm[i].push_back(1);
		for(int x : v[i]){
			sufm[i].push_back(sufm[i].back() * x % 10);
		}
	}
	go();

	if(!an)	
		return cout << -1 << endl, 0;
	vector<int> ans;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < cnt[i] - bst_choose[i]; j++)
			ans.push_back(v[i][j]);
	}
	cout << ans.size() << "\n";
	for(int x : ans){
		cout << x << " ";
	}
	return cout << endl, 0;
}
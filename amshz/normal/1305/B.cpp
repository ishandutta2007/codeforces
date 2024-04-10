# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e6+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, k;
bool mark[xn];
string a;
vector <vector <int> > VC;




int main(){
	fast_io;
	
	cin >> a;
	n = a.size();
	
	while (true){
		vector <int> vec;
		int p1 = 0, p2 = n - 1;
		while (p1 < p2){
			while ((a[p1] == ')' || mark[p1]) && p1 < p2) p1 ++;
			while ((a[p2] == '(' || mark[p2]) && p1 < p2) p2 --;
			if (a[p1] == '(' && a[p2] == ')'){
				vec.push_back(p1 + 1);
				vec.push_back(p2 + 1);
				mark[p1] = mark[p2] = true;
				p1 ++, p2 --;
			}
		}
		if (vec.size() == 0) break;
		sort(vec.begin(), vec.end());
		VC.push_back(vec);
	}
	cout << VC.size() << endl;
	for (int i = 0; i < VC.size(); i ++){
		cout << VC[i].size() << endl;
		for (int j = 0; j < VC[i].size(); j ++) cout << VC[i][j] << sep;
		cout << endl;
	}
	
	
	
	return 0;
}
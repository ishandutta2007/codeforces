#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define y1 asd
#define left asdleft
#define right asdright
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

vector<string> solve(string s){
	vector<string> ans;
	string now = "";
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == ',' || s[i] == ';'){
			ans.push_back(now);
			now = "";
		}else{
			now += s[i];
		}
	}
	ans.push_back(now);
	return ans;
}

bool check(string s){
	for(int i = 0; i < (int) s.size(); i++){
		if(!('0' <= s[i] && s[i] <= '9'))
			return false;
	}
	if(s.empty())
		return false;
	if(s == "0")
		return true;
	if(s[0] == '0')
		return false;
	return true;
}

void print(vector<string> v){
	if(v.empty()){
		cout << "-" << endl;
		return;
	}
	cout << '"';
	for(int i = 0; i < (int) v.size(); i++){
		if(i)
			cout << ",";
		cout << v[i];
	}
	cout << '"' << endl;
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
//output;
#else

#endif

	string s;
	cin >> s;
	vector<string> vec = solve(s);
	vector<string> v1, v2;
	for(int i = 0; i < (int) vec.size(); i++){
		if(check(vec[i]))
			v1.push_back(vec[i]);
		else
			v2.push_back(vec[i]);
	}

	print(v1);
	print(v2);

}
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <pii, pii> pip;
 
# define A 					first
# define B 					second
# define endl 				'\n'
# define sep 				' '
# define all(x) 			x.begin(), x.end()
# define kill(x)         	return cout << x << endl, 0
# define InTheNameOfGod 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

vector < vector <int> > Lines;
int c[xn], S, val;
char a[xm];
bool WinLose[xn];

void PreProcces(){
	vector <int> line;
	line.push_back(0);
	line.push_back(1);
	line.push_back(2);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(3);
	line.push_back(4);
	line.push_back(5);
	line.push_back(6);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(7);
	line.push_back(8);
	line.push_back(9);
	line.push_back(10);
	line.push_back(11);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(12);
	line.push_back(13);
	line.push_back(14);
	line.push_back(15);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(16);
	line.push_back(17);
	line.push_back(18);
	Lines.push_back(line);
	
	//// ******************
	
	line.clear();
	line.push_back(2);
	line.push_back(6);
	line.push_back(11);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(1);
	line.push_back(5);
	line.push_back(10);
	line.push_back(15);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(0);
	line.push_back(4);
	line.push_back(9);
	line.push_back(14);
	line.push_back(18);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(3);
	line.push_back(8);
	line.push_back(13);
	line.push_back(17);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(7);
	line.push_back(12);
	line.push_back(16);
	Lines.push_back(line);
	
	//// ******************
	
	line.clear();
	line.push_back(0);
	line.push_back(3);
	line.push_back(7);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(1);
	line.push_back(4);
	line.push_back(8);
	line.push_back(12);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(2);
	line.push_back(5);
	line.push_back(9);
	line.push_back(13);
	line.push_back(16);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(6);
	line.push_back(10);
	line.push_back(14);
	line.push_back(17);
	Lines.push_back(line);
	
	line.clear();
	line.push_back(11);
	line.push_back(15);
	line.push_back(18);
	Lines.push_back(line);
	for (vector <int> vec : Lines){
		for (int i = 0; i < vec.size(); ++ i){
			int sum = 0;
			for (int j = i; j < vec.size(); ++ j){
				sum += (1 << vec[j]);
				c[S ++] = sum;
			}
		}
	}
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 19; ++ i) cin >> a[i];
	for (int i = 0; i < 19; ++ i)
		if (a[i] == 'O')
			val += (1 << i);
	PreProcces();
	for (int mask = 1; mask < (1 << 19); ++ mask){
		for (int i = 0; i < S; ++ i){
			if ((mask&c[i]) < c[i]) continue;
			WinLose[mask] |= !WinLose[mask - c[i]];
		}
	}
	if (WinLose[val]) cout << "Karlsson" << endl;
	else cout << "Lillebror" << endl;
	
	return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
//#include <unordered_map>
#include <utility>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <ctime>
#include <vector>
using namespace std;
#define i64         long long
#define rep(i, n)   for(i64 i = 0; i < ((i64)(n)); ++i)
#define sz(v)       ((i64)((v).size()))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define all(v)      (v).begin(), (v).end()

/*template <int POS, class TUPLE> void deploy(std::ostream &os, const TUPLE &tuple){}
template <int POS, class TUPLE, class H, class ...Ts> void deploy(std::ostream &os, const TUPLE &t){ os << (POS == 0 ? "" : ", ") << get<POS>(t); deploy<POS + 1, TUPLE, Ts...>(os, t); }
template <class ...Ts> std::ostream& operator<<(std::ostream &os, const std::tuple<Ts...> &t){ os << "("; deploy<0, std::tuple<Ts...>, Ts...>(os, t); os << ")"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> &q){ os << "{"; for(; !q.empty(); q.pop()){ os << q.front() << (q.size() != 1 ? ", " : ""); } os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> &q){ os << "{"; for(; !q.empty(); q.pop()){ os << q.top() << (q.size() != 1 ? ", " : ""); } os << "}"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> &p){ os << "(" << p.first << ", " << p.second << ")"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "" : ", "); os << "}"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "" : ", "); os << "}"; return os; }
#define DEBUG1(var0) { std::cout << (#var0) << "=" << (var0) << std::endl; }
#define DEBUG2(var0, var1) { std::cout << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << std::endl; }
#define DEBUG3(var0, var1, var2) { std::cout << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << std::endl; }
#define DEBUG4(var0, var1, var2, var3) { std::cout << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << std::endl; }
#define DEBUG5(var0, var1, var2, var3, var4) { std::cout << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << ", " << (#var4) << "=" << (var4) << std::endl; }
#define DEBUG6(var0, var1, var2, var3, var4, var5) { std::cout << (#var0) << "=" << (var0) << ", " << (#var1) << "=" << (var1) << ", " << (#var2) << "=" << (var2) << ", " << (#var3) << "=" << (var3) << ", " << (#var4) << "=" << (var4) << ", " << (#var5) << "=" << (var5) << std::endl; }

*/


#define forn(i, n) for (int i = 0; i < (int) n; ++i)


int main()
{
//	freopen("input.txt", "r", stdin);
/*	freopen("input.txt", "w", stdout);

	i64 n = 1000;
	cout << n << endl;
	forn(i, n) {
		forn(j, n)
			cout << ('0' + rand()%2) << endl;
		cout << endl;
	}
	cout << n * n << endl;
	forn(i, n * n)
		cout << ('1' + rand()%2) << " " << rand()%n << endl;
	return 0;*/

	i64 n;
  cin >> n;
  vector<vector<i64>> a(n, vector<i64>(n));
  rep(i, n)rep(j, n) cin >> a[i][j];
  cerr << clock() << endl;
  
  i64 total = 0;
  rep(x, n)rep(y, n) total += a[x][y] * a[y][x];
  total %= 2;
  
  i64 q;
  cin >> q;
  string ans = "";
  rep(step, q){
    i64 t, b;
	scanf("%I64d", &t);
//    cin >> t;
    if(t == 3){
      ans += string(1, total + '0');
      continue;
    }
//    cin >> b;
	scanf("%I64d", &b);
    total = 1 - total;
  }
  cout << ans << endl;

  cerr << clock() << endl;
}
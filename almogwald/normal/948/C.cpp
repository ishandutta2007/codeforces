#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define forn(i,n) forr(i,1,n,1)
#define forin(i,arr) fori(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define defn def(n)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define vec(a) vector<a>
#define co cout <<
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
#define ex return 0; 
#define out(i) co i <<' ';
#define maxi 1000000013
typedef vector<int> veci;
typedef pair<int, int> point;
typedef pair<veci, int> vecip;
int main() {
	defn
	veci snow(n);
	fori(i, n) {
		into(snow[i]);
	}
	multiset<long long> piles;
	long long sum = 0,melt;
	fori(i, n) {
		into(melt);
		long long sumi = 0;
		piles.insert(snow[i] + sum);
		auto it = piles.begin();
		int j = 0;
		while(it!=piles.end()&&*it<sum+melt){
			sumi += *it-sum;
			piles.erase(it);
			it = piles.begin();
			j++;
		}
		sumi += piles.size()*melt;
		sum += melt;
		out(sumi)
	}
	co "" el
	ex
}
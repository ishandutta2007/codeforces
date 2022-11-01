#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <algorithm>
#include <set>
using namespace std;
#define _ << ' '<<
#define el << endl;
#define ci cin >> 
#define def(i) int i; ci i;
#define co cout <<
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define ex return 0;
#define PI 3.14159265
#define cas(i) co "Case #" << i+1 << ": " <<
typedef pair<int, int> point;
int main()
{
	def(n)
		vector<int> p(n);
	vector<int> childs(n);
	vector<int> has(n);
	if (n <3) {
		co "No" el
			ex
	}
	forr(i, 1, n, 1) {
		def(a);
		a--;
		p[i] = a;
		if (has[a] == 0 && a != 0) {
			childs[p[a]]--;
		}
		childs[a]++;
		has[a] = 1;
		/*fori(i, n) {
			co childs[i] << ' ';
		}
		cout el
			fori(i, n) {
			co has[i] << ' ';
		}
		cout el*/
	}
	fori(i, n) {
		if (has[i] != 0 && childs[i] < 3) {
			co "No" el
				ex
		}
	}
	co "Yes" el
		ex
}
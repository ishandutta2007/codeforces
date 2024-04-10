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
#define def(i) long long int i; ci i;
#define co cout <<
#define forr(i,a,b,c) for(long long int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define ex return 0;
#define PI 3.14159265
#define cas(i) co "Case #" << i+1 << ": " <<
typedef pair<int, int> point;
int main()
{
	def(n) def(L)
	long long int ans=0;
	vector<long long int> a(n);
	ci a[0];
	forr(i, 1, n, 1) {
		ci a[i];
		if (a[i - 1] * 2 < a[i]) {
			a[i] = 2*a[i-1];
		}
	}
	fori(i, n) {
		if (ans > a[i]) {
			ans = a[i];
		}
		if ((L % 2)==1) {
			if (a[i] == -1) {
				L++;
			}
			ans += a[i];
		}
		L /= 2;
	}
	ans += 2*L*a[n - 1];
	co ans el
	ex
}
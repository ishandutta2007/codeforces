#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;
#define _ << ' '<<
#define el << endl;
#define ci cin >> 
#define co cout <<
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define ex return 0;
#define PI 3.14159265


int main()
{
	int n,a,b,c;
	ci a >> b >> c >> n;
	if (a <= n || b <= n || 2 * c < n || c>2 * n) {
		co -1 el
		ex
	}
	co 2 * a el
	co 2 * b el
	if (c > n) {
		co c el
	}
	else {
		co n el
	}
	ex
}
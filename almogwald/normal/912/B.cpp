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
	long long int k,n,ans=0;
	ci n >> k;
	if (k == 1) {
		co n el
		ex
	}	
	while (n > 0) {
		n /= 2;
		ans = ans * 2 + 1;
	}
	co ans el
	ex
}
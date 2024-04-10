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
	long long int a, b,x,y,z;
	ci a >> b >> x >> y >>  z;
	co max(2*x+y-a,(long long int)0)+ max(3 * z + y - b, (long long int) 0) el
	ex
}
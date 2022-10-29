#include <iostream>
using namespace std;
int main()
{
	int x,y,z,t1,t2,t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	if (t1*abs(x-y)<t2*(abs(z-x)+abs(y-x))+3*t3)
	cout << "NO";
	else
	cout << "YES";
}
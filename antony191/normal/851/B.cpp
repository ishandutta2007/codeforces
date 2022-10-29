#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if (sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by)) == sqrt((cx - bx)*(cx - bx) + (cy - by)*(cy - by)) && !(double(bx) == (ax + cx) / 2.0 && double(by) == (ay + cy) / 2.0))
		cout << "Yes";
	else cout << "No";
	return 0;
}
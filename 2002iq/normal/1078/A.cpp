#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double a,b,c,x1,y1,x2,y2;
double dist(pair<double,double> A,pair<double,double> B)
{
	return hypot(A.first-B.first,A.second-B.second);
}
double get(int xy,int d)
{
	if (d)
	return -(c+b*xy)/a;
	else
	return -(c+a*xy)/b;
}
double go(int d1,int d2)
{
	if (((d1 || d2) && !b) || ((!d1 || !d2) && !a))
	return 1e19;
	pair<double,double> A,B;
	if (d1)
	A={x1,get(x1,0)};
	else
	A={get(y1,1),y1};
	if (d2)
	B={x2,get(x2,0)};
	else
	B={get(y2,1),y2};
	return dist({x1,y1},A)+dist(A,B)+dist({B},{x2,y2});
}
int main()
{
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	cout << setprecision(9) << fixed << min(fabs(x1-x2)+fabs(y1-y2),min(min(go(0,0),go(0,1)),min(go(1,0),go(1,1))));
}
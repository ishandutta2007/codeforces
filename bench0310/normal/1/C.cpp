#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double sq(double n);
double gcd(double x,double y);

int main()
{
    ios::sync_with_stdio(false);
    double x[3],y[3];
    for(int i=0;i<3;i++) cin >> x[i] >> y[i];
    //Define PI
    double PI=3.141592653;
    //Sides
    double a=sqrt(sq(x[0]-x[1])+sq(y[0]-y[1]));
    double b=sqrt(sq(x[1]-x[2])+sq(y[1]-y[2]));
    double c=sqrt(sq(x[2]-x[0])+sq(y[2]-y[0]));
    //Area
    double area=0.25*sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
    //Radius
    double r=(a*b*c)/(4*area);
    //Angles
    double d=acos((b*b+c*c-a*a)/(2*b*c));
	double e=acos((a*a+c*c-b*b)/(2*a*c));
	double f=acos((b*b+a*a-c*c)/(2*b*a));
    //Greatest common divisor
    double g=gcd(gcd(d,e),f);
    //Number of polygon sides
    double n=(PI)/(g);
    //Final area
    double res=n*r*r*0.5*sin(2*PI/n);
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}

double sq(double n)
{
    return n*n;
}

double gcd(double x,double y)
{
	return fabs(y)<1e-4?x:gcd(y,fmod(x,y));
}
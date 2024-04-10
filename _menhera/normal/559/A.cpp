#define sin120 0.86602540378443864676372317075294
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    vector<double> v;
    double air,air1,air2,air3,air4;
    int x,y;
    cin >> x >> y ;
    v.push_back( sqrt(x*x+y*y+x*y) );
    air1=sin120*x*y*0.5;
    
    cin >> x >> y ;
    v.push_back( sqrt(x*x+y*y+x*y) );
    air2=sin120*x*y*0.5;

    cin >> x >> y ;
    v.push_back( sqrt(x*x+y*y+x*y) );
    air3=sin120*x*y*0.5;

    double a=v[0],b=v[1],c=v[2];	
	air4=sqrt((a+b-c)*(a-b+c)*(b+c-a)*(a+b+c))/4.;

    air=air1+air2+air3+air4;

    cout << (int)((air * 4)/sqrt(3) +0.5);
	return 0;
}
#include <iostream>
using namespace std;
int x,y,p;
int main()
{
    cin >> x >> y;
    if ((y>x) && (x>=-y))
		p=-2+y*4;
    if((y>=x) && (x<-y))
    	p=-1+4*-x;
    if((x>y) && (-x+1>=y))
		p=-y*4;
    if((x>=y) && (-x+1<y))
		p=-3+x*4;
    cout << p;
    return 0;
}
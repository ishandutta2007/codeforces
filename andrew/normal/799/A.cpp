#include <iostream>
#include <cmath>
using namespace std;
long long x,xx,x1,x2,n,t,k,i,j,d;
//double x,xx;
int main()
{
    cin >> n >> t >> k >> d;
    for(i=1;i<=10000001;i++)
    {
        if(i%t==0)x+=k,xx+=k;
        if(x>=n)
        {
            cout << "NO" << endl;
            return 0;
        }
        if(i-d>0 && (i-d)%t==0)xx+=k;
        if(xx>=n)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    return 0;
}
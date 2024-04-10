#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int d=0;
    int x=1000000000;
    while(d*d<=n)
    {
        d++;
        if(n%d) continue;
        //d,n/d
        if((n/d)<k) x=min(x,k*d+(n/d));
        //n/d,d
        if(d<k) x=min(x,n*k/d+d);
    }
    cout << x << endl;
    return 0;
}
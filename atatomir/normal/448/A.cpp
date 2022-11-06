#include <iostream>

using namespace std;

long c=4,m=9,x,i;

int main()
{
    for(i=1;i<=3;i++) {
        cin >> x;
        c+= x;
    }
    for(i=1;i<=3;i++) {
        cin >> x;
        m+= x;
    }
    c/= 5; m/= 10;
    cin >> x;

    if (x >= c+m)
        cout << "YES" ;
    else
        cout << "NO";

    return 0;
}
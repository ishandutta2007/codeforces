#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a!=d) cout << a << " " << d << endl;
        else cout << a << " " << d-1 << endl;
    }
    return 0;
}
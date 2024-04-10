#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int x;
    for(int i=0;i<t;i++)
    {
        cin >> x;
        cout << (int)pow(2,__builtin_popcount(x)) << endl;
    }
    return 0;
}
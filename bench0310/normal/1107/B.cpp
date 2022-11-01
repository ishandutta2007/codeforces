#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long k,x;
        cin >> k >> x;
        cout << x+9*(k-1) << endl;
    }
    return 0;
}
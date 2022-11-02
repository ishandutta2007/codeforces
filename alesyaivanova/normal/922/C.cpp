#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    n++;
    for (; k > 0; k--)
    {
        if (n % k)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
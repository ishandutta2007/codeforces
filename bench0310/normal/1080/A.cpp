#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n,k;
    cin >> n >> k;
    cout << (2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k << endl;
    return 0;
}
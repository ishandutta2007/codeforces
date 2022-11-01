#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    if(k==1 || n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    if(k<=n)
    {
        cout << (k-1)/2 << endl;
        return 0;
    }
    long long num=2*n-k+1;
    if(num/2<0) cout << 0 << endl;
    else cout << num/2 << endl;
    return 0;
}
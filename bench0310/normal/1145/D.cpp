#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int m=32;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        m=min(m,a[i]);
    }
    cout << 2+(a[2]^m) << endl;
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int l[n],r[n];
    for(int i=0;i<n;i++) cin >> l[i] >> r[i];
    int k;
    cin >> k;
    for(int i=0;i<n;i++)
    {
        if(l[i]<=k&&k<=r[i])
        {
            cout << n-i << endl;
            break;
        }
    }
    return 0;
}
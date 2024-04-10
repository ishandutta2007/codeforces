#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int idx=0;
    for(int i=0;i<n;i++)
    {
        cout << (arr[i]+idx)/m << " ";
        idx=(arr[i]+idx)%m;
    }
    return 0;
}
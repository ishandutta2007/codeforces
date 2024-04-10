#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    if(arr[0]!=0)
    {
        cout << 1 << endl;
        return 0;
    }
    int m=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>m+1)
        {
            cout << i+1 << endl;
            return 0;
        }
        m=max(m,arr[i]);
    }
    cout << -1 << endl;
    return 0;
}
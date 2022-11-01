#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n+1][2];
    for(int i=1;i<=n;i++) cin >> arr[i][0] >> arr[i][1];
    int res[n];
    res[0]=1;
    int a=arr[1][0],b=arr[1][1];
    if(arr[a][0]==b||arr[a][1]==b)
    {
        res[1]=a;
        res[2]=b;
    }
    else
    {
        res[1]=b;
        res[2]=a;
    }
    for(int i=3;i<n;i++)
    {
        if(arr[res[i-2]][0]==res[i-1]) res[i]=arr[res[i-2]][1];
        else res[i]=arr[res[i-2]][0];
    }
    for(int i=0;i<n;i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n;i+=2) cnt+=(arr[i+1]-arr[i]);
    cout << cnt << endl;
    return 0;
}
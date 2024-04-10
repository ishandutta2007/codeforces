#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int idx=0,sub=0,total=0;
    while(k--)
    {
        sub=arr[idx];
        cout << arr[idx]-total << endl;
        total+=arr[idx]-total;
        idx++;
        while(idx<n&&arr[idx]==total) idx++;
        if(idx==n)
        {
            k--;
            break;
        }
    }
    k++;
    while(k--) cout << 0 << endl;
    return 0;
}
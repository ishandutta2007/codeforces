#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,s;
    cin >> n >> s;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int mid=(n-1)/2;
    int median=arr[mid];
    long long cnt=0;
    if(median==s)
    {
        cout << 0 << endl;
    }
    else if(median<s)
    {
        int idx=mid;
        while(idx<n && arr[idx]<s)
        {
            cnt+=(s-arr[idx]);
            idx++;
        }
        cout << cnt << endl;
    }
    else if(median>s)
    {
        int idx=mid;
        while(idx>=0 && arr[idx]>s)
        {
            cnt+=(arr[idx]-s);
            idx--;
        }
        cout << cnt << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
struct T
{
    int x;
    int y;
};
 
int binarySearch(int arr[], int l, int r, int x) /// [l;r)
{
    while(r > l)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            return binarySearch(arr, l, mid, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
//int matrix[4000][4000];
 
int main()
{
 
    long long t, n, m, d, s, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> k;
        long long minim = n;
        int a[1000];
        for(int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        sort(a, a + k);
        int ans = 0;
        for(int i = 0; i <= k; i++)
        {
            if((s + i <= n && binarySearch(a, 0, k, s + i) < 0) || (s - i > 0 && binarySearch(a, 0, k, s - i) < 0))
            {
                ans = i;
                break;
            }
 
        }
        cout << ans << endl;
    }
 
}
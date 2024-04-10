#include<iostream>
#include<bits/stdc++.h>
#define int long long int 
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t;cin>>t;
    while(t--)
    {
        int arr[4];
        for(int i=0;i<4;i++)
        cin>>arr[i];

        sort(arr,arr+4);
        cout<<arr[0]*arr[2]<<endl;
    }


    return 0;
}
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    
    int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    
    long long int x,y,z,sum;
    
    cout<<"? 1 2"<<endl;
    cin>>x;
    cout<<"? 2 3"<<endl;
    cin>>y;
    cout<<"? 1 3"<<endl;
    cin>>z;
    arr[2]=z-x;
    arr[1]=x+y-z;
    arr[0]=z-y;
    
    for(int i=3;i<n;i++)
    {
        cout<<"? "<<i<<" "<<i+1<<endl;
        cin>>sum;
        arr[i]=sum-arr[i-1];
    }
    
    cout<<"! ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
   cout<<endl;
    return 0;
}
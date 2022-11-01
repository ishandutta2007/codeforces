#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    int sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    for(int o=0;o<k;o++)
    {
        int temp=sum;
        for(int i=o;i<n;i+=k) temp-=arr[i];
        if(temp<0) temp=-temp;
        res=max(res,temp);
    }
    cout << res << endl;
    return 0;
}
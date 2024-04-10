#include <iostream>

using namespace std;

int abs(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int t,res=10000000;
    for(int o=1;o<=100;o++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i]-o)>1)
            {
                if(arr[i]>o) cnt+=arr[i]-o-1;
                else cnt+=o-1-arr[i];
            }
        }
        if(cnt<res)
        {
            t=o;
            res=cnt;
        }
    }
    cout << t << " " << res << endl;
    return 0;
}
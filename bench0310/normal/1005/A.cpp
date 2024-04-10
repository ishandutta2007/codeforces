#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt=0;
    int stairs[10000];
    int nums[1001];
    for(int i=0;i<n;i++) cin >> nums[i];
    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        {
            cnt++;
            if(i)
            {
                stairs[idx]=nums[i-1];
                idx++;
            }
        }
        if(i==n-1)
        {
            stairs[idx]=nums[i];
            idx++;
        }
    }
    cout << cnt << endl;
    for(int i=0;i<idx;i++) cout << stairs[i] << " ";
    cout << endl;
    return 0;
}
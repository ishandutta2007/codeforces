#include <iostream>

using namespace std;

bool doable(int parts,int value,int n,int arr[]);

int main()
{
    int n;
    cin >> n;
    char temp[n+1];
    cin >> temp;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=(temp[i]-'0');
        sum+=arr[i];
    }
    bool good=0;
    for(int i=2;i<=sum;i++)
    {
        if(sum%i==0)
        {
            if(doable(i,sum/i,n,arr))
            {
                good=1;
                break;
            }
        }
    }
    if(doable(2,0,n,arr)) good=1;
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

bool doable(int parts,int value,int n,int arr[])
{
    if(parts>n) return 0;
    bool good=1;
    int curSum=0;
    for(int i=0;i<n;i++)
    {
        curSum+=arr[i];
        if(curSum>value)
        {
            good=0;
            break;
        }
        if(curSum==value)
        {
            curSum=0;
            continue;
        }
    }
    if(curSum>0) good=0;
    return good;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n,h,a,res=0,summ=0,k,i=0,done=0,now=0,ivan    ;
    cin>>n>>h>>k;
    vector<long long> arr;
    for (long long i=0;i<n;++i)
    {
        cin>>a;
        arr.push_back(a);
        summ+=a;
    }
    arr.push_back(h+1);
    while (1)
    {
        while (i<n && now+arr[i]<=h)
        {
            now+=arr[i];
            i++;
        }
        ivan=now/k;
        now-=min(now,ivan*k);
        if (now+arr[i]>h && now!=0)
        {
            ivan++;
            now=0;
        }
        res+=ivan;
        if (i>=n && now==0) break;
    }
    cout<<res;
}
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int count1=0;
    int count2=0;
    int count3=0;
    int ans=0;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]==4)
        {
            ans++;
        }
        else if(v[i]==3)
        {
            count3++;
        }
        else if(v[i]==2)
        {
            count2++;
        }
        else
        {
            count1++;
        }
    }
    count1=count1-count3;
    ans+=count3;
    ans+=count2/2;
    if(count2%2!=0)
    {
        ans+=1;
        count1=count1-2;
    }
    if(count1>0)
    {
        ans=ans+((count1+3)/4);
    }
    cout<<ans;
    return 0;
}
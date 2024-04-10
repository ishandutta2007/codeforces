#include <bits/stdc++.h>
using namespace std;

int n,k;
deque<int> a;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    while(1)
    {
        if(a.empty())
            break;
        if(a.front()<=k)
        {
            a.pop_front();
            continue;
        }
        if(a.back()<=k)
        {
            a.pop_back();
            continue;
        }
        break;
    }
    cout<<n-a.size()<<endl;
    return 0;
}
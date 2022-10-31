#include <bits/stdc++.h>
using namespace std;
int n,best=-1000*1000,a,now,one;
int main()
{ 
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a)
            now--,one++;
        else
            now++;
        best=max(best,now);
        if(now<0)
            now=0;          
    }
    cout<<best+one;
    return 0;
}
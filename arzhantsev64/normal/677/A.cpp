#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,h,a,res=0;
    cin>>n>>h;
    for (int i=0;i<n;++i)
    {
        cin>>a;
        res++;
        if (a>h)
            res++;
    }
    cout<<res;
}
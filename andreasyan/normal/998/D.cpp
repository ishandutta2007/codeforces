#include <bits/stdc++.h>

using namespace std;
const int m=1600;

int solv(int n)
{
    bool a[m]={};
    a[0]=true;
    for(int i=0;i<n;++i)
    {
        bool b[m]={};
        for(int j=m-1;j>=0;--j)
            if(a[j])
            {
                if(j+1<m)
                    b[j+1]=true;
                if(j+5<m)
                    b[j+5]=true;
                if(j+10<m)
                    b[j+10]=true;
                if(j+50<m)
                    b[j+50]=true;
            }
        for(int j=0;j<m;++j)
            a[j]=b[j];
    }
    int ans=0;
    for(int i=0;i<m;++i)
        if(a[i]==true)
            ++ans;
    return ans;
}

int main()
{
    //for(int i=1;i<30;++i)
    //    cout<<i<<' '<<solv(i)<<endl;
    long long n;
    cin>>n;
    if(n<=20)
        cout<<solv(n)<<endl;
    else
        cout<<solv(20)+(49*(n-20))<<endl;
    return 0;
}
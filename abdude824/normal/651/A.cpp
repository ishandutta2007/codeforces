#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    while(a>0&&b>0)
    {
        ans++;
        if(a>b)
            swap(a,b);
        a++;
        b-=2;
        if(a<0||b<0)
        {
            ans--;
            break;
        }
    }
    cout<<ans<<endl;
}
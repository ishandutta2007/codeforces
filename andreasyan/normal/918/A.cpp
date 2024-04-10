#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int N=1002;

int n;
int a[N];
int main()
{
    cin>>n;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;++i)
        a[i]=a[i-1]+a[i-2];
    int j=1;
    for(int i=1;i<=n;++i)
        if(i==a[j])
        {
           cout<<'O';
           ++j;
        }
        else
            cout<<'o';
    cout<<endl;
    return 0;
}
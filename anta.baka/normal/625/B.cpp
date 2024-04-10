#include <iostream>
#include <string>
using namespace std;

string a,b;
int n,m;

int main()
{
    cin>>a>>b;
    n=a.length();
    m=b.length();

    int cnt=0;
    for(int i=0; i<n; i++)
        if(a.substr(i,m)==b)
            i+=m-1,cnt++;

    cout<<cnt;
    return 0;
}
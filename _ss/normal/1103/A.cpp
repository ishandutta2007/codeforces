#include <iostream>
#include <cstring>
using namespace std;
string s;
int main()
{
    cin>>s;
    int n=s.length(),t1=0,t2=0;
    for (int i=0;i<n;i++)
        if (s[i]=='0')
        {
            cout<<1<<" "<<t1+1<<endl;
            t1=(t1+1)%4;
        }
        else
        {
            cout<<3<<" "<<t2*2+1<<endl;
            t2=(t2+1)%2;
        }
    return 0;
}
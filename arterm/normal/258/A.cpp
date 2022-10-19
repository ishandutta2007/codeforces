#include <iostream>
#include <string>

using namespace std;

string s;
long n;

int main()
{
    cin>>s;
    n=s.length();
    for (long i=0; i+1<n; ++i)
        if (s[i]=='1')
        cout<<1;
        else{
            cout<<s.substr(i+1,n-i-1);
            return 0;
        }
    return 0;
}
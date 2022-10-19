#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    long n;
    cin>>s;
    n=s.length();
    if (s[0]=='h'){
        cout<<"http://";
        s=s.substr(4,n-4);
    }
    else{
        cout<<"ftp://";
        s=s.substr(3,n-3);
    }
    n=s.length();
    for (long i=1; ; ++i)
    if (s[i]=='r' && s[i+1]=='u'){
            cout<<s.substr(0,i)<<".ru";
            if (n>i+2)
            cout<<"/"<<s.substr(i+2,n-i-2);
            return 0;
        }
    return 0;
}
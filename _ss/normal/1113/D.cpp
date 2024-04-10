#include <iostream>
#include <cstring>
using namespace std;
string s;
bool doixung(int r)
{
    for (int i=0;i<(r+1)/2;i++)
        if (s[i]!=s[r-i]) return false;
    return true;
}
int main()
{
    cin>>s;
    int mid=s.length();
    bool kt=true,kt3=true;
    for (int i=1;i<s.length()/2;i++)
        if (s[i]!=s[i-1]) kt3=false;
    if (kt3)
    {
        cout<<"Impossible";
        return 0;
    }
    while (doixung(mid-1))
    {
        if (mid%2==1)
        {
            kt=false;
            break;
        }
        mid=mid/2;
    }
    if (kt) cout<<1; else cout<<2;
    return 0;
}
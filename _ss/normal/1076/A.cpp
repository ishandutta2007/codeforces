#include <iostream>

using namespace std;

int main()
{
    string s;
    int i=0,n,t;
    cin>>n;
    cin>>s;
    while (i<n-2 && s[i]<=s[i+1]) i++;
    if (s[i]<=s[i+1]) t=i+1; else t=i;
    for (i=0;i<t;i++) cout<<s[i];
    for (int i=t+1;i<n;i++) cout<<s[i];
    return 0;
}
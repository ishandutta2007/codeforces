#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int d=0;
    int i=0,j=s.length()-1;
    while (i<j && s[i]!='[') i++;
    if (s[i]=='[') d++;
    while (i<j && s[i]!=':') i++;
    if (s[i]==':') d++;
    while (j>i && s[j]!=']') j--;
    if (s[j]==']') d++;
    while (j>i && s[j]!=':') j--;
    if (s[j]==':') d++;
    if (i>=j || d<4)
    {
        cout<<-1;
        return 0;
    }
    while (i<j)
    {
        if (s[i]=='|') d++;
        i++;
    }
    cout<<d;
    return 0;
}
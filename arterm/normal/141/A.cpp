#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,long> f,e;

int main()
{
    string s;
    char ch;
    cin>>s;
    for (long i=0; i<s.length(); ++i)
    ++f[s[i]];
    cin>>s;
    for (long i=0; i<s.length(); ++i)
    ++f[s[i]];
    cin>>s;
    for (long i=0; i<s.length(); ++i)
    ++e[s[i]];
    for (ch='A'; ch<='Z'; ++ch)
    if (f[ch]!=e[ch]){
                      cout<<"NO";
                      return 0;
                      }
    cout<<"YES";
    return 0;
}
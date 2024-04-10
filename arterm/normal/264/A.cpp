#include <iostream>
#include <string>
#include <deque>

using namespace std;

string s;
long n;
deque<long> d;

int main()
{
    cin>>s;
    n=s.length();
    for (long i=n-1; i>=0; --i)
    if (s[i]=='l')
    d.push_back(i+1);
    else
    d.push_front(i+1);
    for (long i=0; i<n; ++i,cout<<"\n")
    cout<<d.front(),d.pop_front();
    return 0;
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int n,m;
map<string,string> a;
int main()
{
    string s1,s2;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>s1>>s2;
        s2+=';';
        a[s2]=s1;
    }
    for(int i=0;i<m;++i)
    {
        cin>>s1>>s2;
        cout<<s1<<' '<<s2<<" #"<<a[s2]<<endl;
    }
    return 0;
}
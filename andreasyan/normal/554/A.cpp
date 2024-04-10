#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const int N=22;

string a;
string p[N];
string s[N];
set<string> ans;
int main()
{
    int n;
    cin>>a;
    n=a.size();
    p[0]=a[0];
    for(int i=1;i<n;++i)
    {
        p[i]=p[i-1]+a[i];
    }
    s[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i)
    {
        s[i]=s[i+1]+a[i];
    }
    for(int j=0;j<26;++j)
    {
        string x;
        x+=(j+'a');
        x+=a;
        ans.insert(x);
    }
    for(int i=0;i<n;++i)
    {
        reverse(s[i+1].begin(),s[i+1].end());
        for(int j=0;j<26;++j)
        {
            string x;
            x=p[i];
            x+=(j+'a');
            x+=s[i+1];
            ans.insert(x);
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}
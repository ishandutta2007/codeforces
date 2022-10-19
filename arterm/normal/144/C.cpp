#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s,p;
    vector<long> t(30,0),pt(30,0);
    long n,k,i,j,ans=0;
    bool f;
    cin>>s>>p;
    k=p.length();
    n=s.length();
    if (n<k){
             cout<<0;
             return 0;
             }
    for (i=0; i<k; ++i){
        ++pt[p[i]-'a'];
        if (s[i]!='?')
        ++t[s[i]-'a'];
        }
    for (i=0; i<=n-k; ++i){
        f=1;
        for (j=0; j<26; ++j)
        if (t[j]>pt[j]){
                        f=0;
                        break;
                        }
        if (f)
        ++ans;
        if (s[i]!='?')
        --t[s[i]-'a'];
        if (i!=n-k)
        if (s[i+k]!='?')
        ++t[s[i+k]-'a'];
        }
    cout<<ans;
    //system("PAUSE");
    return 0;
}
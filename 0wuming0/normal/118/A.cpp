#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    cin>>s;
    for(int i=0;s[i];i++)
    {
        if(s[i]<='Z')s[i]+='a'-'A';
        if(s[i]=='a'||s[i]=='o'||s[i]=='y'||s[i]=='e'||s[i]=='u'||s[i]=='i')continue;
        cout<<"."<<s[i];
    }
    cout<<endl;
    return 0;
}
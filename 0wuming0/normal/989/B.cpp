#include"bits/stdc++.h"
using namespace std;
char s[2005];
int main()
{
    int n,p;
    cin>>n>>p;
    cin>>s;
    for(int i=0;i+p<n;i++)if(s[i]!=s[i+p]||s[i]=='.')
    {
        if(s[i]=='.'&&s[i+p]=='.')
        {
            s[i]='0';
            s[i+p]='1';
        }
        else
        {
            if(s[i]=='.')
            {
                s[i]='0'+(1^(s[i+p]-'0'));
            }
            else if(s[i+p]=='.')
            {
                s[i+p]='0'+(1^(s[i]-'0'));
            }
        }
        for(int i=1;i<n;i++)if(s[i]=='.')
        {
            s[i]=rand()%2+'0';
        }
        cout<<s<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    int n;cin>>n;
    int t;cin>>t;
    string s;cin>>s;
    while(t--)
    {
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='B'&&s[i+1]=='G')
            {
                s[i]='G';s[i+1]='B';i++;
            }
        }
    }
    cout<<s<<endl;

}
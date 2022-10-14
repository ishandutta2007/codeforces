#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    string s1,s2;cin>>s1>>s2;
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
        s1[i]=tolower(int (s1[i]));
        s2[i]=tolower(int (s2[i]));
        if(s1[i]>s2[i])
        {cout<<"1"<<endl;break;}
        else if(s1[i]<s2[i]){cout<<"-1"<<endl;break;}

        if(i==n-1)
            {cout<<"0"<<endl;break;}
    }
}
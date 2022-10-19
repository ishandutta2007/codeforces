#include"bits/stdc++.h"
using namespace std;
int num[505];
char s1[1005],s2[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i='A';i<='Z';i++)num[i]=0;
        cin>>s1>>s2;
        vector<char>v1,v2;
        for(int i=0;s2[i];i++)
        {
            num[s2[i]]++;
            v2.push_back(s2[i]);
        }
        int n=strlen(s1);
        for(int i=n-1;i>=0;i--)
        {
            num[s1[i]]--;
            if(num[s1[i]]>=0)v1.push_back(s1[i]);
        }
        for(int i=0,j=(int)v1.size()-1;i<j;i++,j--)swap(v1[i],v1[j]);
        if(v1==v2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
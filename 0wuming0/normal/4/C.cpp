#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    map<string,int>mp;
    while(n--)
    {
        string s;
        cin>>s;
        int t=mp[s]++;
        if(t==0)
        {
            printf("OK\n");
        }
        else
        {
            cout<<s;
            printf("%d\n",t);
        }
    }
    return 0;
}
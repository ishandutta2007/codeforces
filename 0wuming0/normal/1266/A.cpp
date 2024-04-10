#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[105];
        cin>>s;
        int a[405]={0};
        int num=0;
        for(int i=0;s[i];i++)
        {
            num+=s[i]-'0';
            a[s[i]]++;
        }
        if(a['0']==0||num%3!=0||a['0']+a['2']+a['4']+a['6']+a['8']<=1)
        {
            cout<<"cyan"<<endl;
        }
        else cout<<"red"<<endl;
    }
    return 0;
}
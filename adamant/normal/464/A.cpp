#include <bits/stdc++.h>

using namespace std;

main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    for(int i=n-1;i>=0;i--)
    {
        char t=s[i]+1;
        while(i>0 && t==s[i-1]) t++;
        while(i>1 && t==s[i-2]) t++;
        while(i>0 && t==s[i-1]) t++;
        while(i>1 && t==s[i-2]) t++;
        while(i>0 && t==s[i-1]) t++;
        while(i>1 && t==s[i-2]) t++;
        if(t-'a'>=p) continue;
        string T=s;
        T[i]=t;
        for(int j=i+1;j<n;j++)
        {
            T[j]='a';
            while(j>0 && T[j]==T[j-1]) T[j]++;
            while(j>1 && T[j]==T[j-2]) T[j]++;
            while(j>0 && T[j]==T[j-1]) T[j]++;
            while(j>1 && T[j]==T[j-2]) T[j]++;
            while(j>0 && T[j]==T[j-1]) T[j]++;
            while(j>1 && T[j]==T[j-2]) T[j]++;
            if(T[j]-'a'>=p) continue;
        }
        cout<<T;
        return 0;
        NXT:;
    }
    cout<<"NO";
}
#include"bits/stdc++.h"
using namespace std;
int num[500];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i='a';i<='z';i++)num[i]=0;
        string a,b;
        cin>>a>>b;
        for(auto c:a)num[c]++;
        if(b=="abc"&&num['a']&&num['b']&&num['c'])
        {
            while(num['a']--)putchar('a');
            while(num['c']--)putchar('c');
            while(num['b']--)putchar('b');
            for(int i='d';i<='z';i++)while(num[i]--)putchar(i);
            cout<<endl;
            continue;
        }
        for(int i='a';i<='z';i++)
        {
            while(num[i]--)putchar(i);
        }
        cout<<endl;
    }
    return 0;
}
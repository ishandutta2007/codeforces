#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long


void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll q = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    int n;
    cin>>n;
    vector<char> op(n);
    
    vector<int> a(n);
    
    for (int i = 0; i<n; i++)
    {
        cin>>op[i]>>a[i];
    }
    
    int x1 = 0;
    int x2 = 1023;
    for (int i = 0; i<n; i++)
    {
        if (op[i]=='^') {x1^=a[i]; x2^=a[i];}
        if (op[i]=='&') {x1&=a[i]; x2&=a[i];}        
        if (op[i]=='|') {x1|=a[i]; x2|=a[i];}
    }
    
    cout<<3<<endl;
    int a1 = 0;
    int a2 = 1023;
    int a3 = 0;
    for (int i = 0; i<10; i++)
    {
        bool y = x1&(1<<i);
        bool z = x2&(1<<i);
        if (y==1&&z==0) a1+=(1<<i);
        if (y==0&&z==0) a2-=(1<<i);
        if (y==1&&z==1) a3+=(1<<i);
    }
    cout<<"^ "<<a1<<endl;
    cout<<"& "<<a2<<endl;
    cout<<"| "<<a3<<endl;
}
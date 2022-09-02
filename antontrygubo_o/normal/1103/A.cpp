#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int count0 = 0;
    int count1 = 0;
    for (int i = 0; i<s.length(); i++)
    {
        if (s[i]=='0') {cout<<1+2*count0<<' '<<1<<endl; count0 = 1-count0;}
        if (s[i]=='1') {cout<<1+count1<<' '<<2<<endl; count1 = (count1+1)%4;}
    }

}
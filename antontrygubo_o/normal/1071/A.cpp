#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    ll a, b;
    cin>>a>>b;
    ll temp = sqrt(8*(a+b)+1);
    temp -=1;
    temp/=2;
    vector<int> a1;
    vector<int> b1;
    for (int i = temp; i>=1; i--)
    {
        if (a>=i) {a1.push_back(i); a-=i;}
        else {b1.push_back(i); b-=i;}
    }
    cout<<a1.size()<<endl;
    for (int i = 0; i<a1.size(); i++) cout<<a1[i]<<' ';
    cout<<endl;
    cout<<b1.size()<<endl;
    for (int i = 0; i<b1.size(); i++) cout<<b1[i]<<' ';
    cout<<endl;
}
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int g(char k)
{
    return int(k) - int('0');
}

int f(string s)
{
    return g(s[0]) + 2*g(s[1]) + 4*g(s[2]) + 8*g(s[3]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int a[16];
    for (int i = 0; i<16; i++) a[i] = 0;
    int n, k;
    cin>>n>>k;
    string temp;
    for (int i = 0; i<n; i++)
    {
        temp.clear();
        string t1;
        for (int j = 0; j<k; j++) {cin>>t1; temp+=t1;}
        while (temp.length()<4) temp+='0';
        a[f(temp)]++;
    }
    for (int i = 0; i<16; i++)
    for (int j = 0; j<16; j++)
    {
        if (a[i]>0&&a[j]>0&& ((i&j) == 0)) {cout<<"YES"; return 0;}
    }
    cout<<"NO";
}
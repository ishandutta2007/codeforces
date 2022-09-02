#include <bits/stdc++.h>

using namespace std;

bool contain(long long a, long long b)
{
    string a1 = to_string(a);
    string b1 = to_string(b);
    int idx = 0;
    bool t = true;
    for (int i = 0; i<b1.length(); i++)
    {
        while (idx<a1.length()&&a1[idx]!=b1[i]) idx++;
        if (idx>=a1.length()) t = false;
        idx++;
    }
    return t;
}


int main() 
{
    long long n;
    cin>>n;
    bool t = false;
    long long i = sqrt(n);
    while ((!t)&&i)
    {
        t = contain(n, i*i);
        if (!t) i--;
    }
    if (!t) cout<<-1;
    else cout<<(to_string(n).length())-(to_string(i*i).length())<<endl;
}
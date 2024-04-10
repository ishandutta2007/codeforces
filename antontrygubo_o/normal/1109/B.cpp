#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
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

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

mt19937 rnd(228);

string s;

bool checkpal(string s1)
{
    for (int i = 0; i<s1.length(); i++) if (s1[i]!=s1[s1.length()-i-1]) return false;
    if (s1==s) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>s;
    
    int n = s.length();
    int counter = 0;
    for (int i = 1; i<n/2; i++) if (s[i]!=s[i-1]) counter++;
    if (counter==0) {cout<<"Impossible"; return 0;}
    for (int i = 1; i<n; i++)
    {
        string temp = s.substr(i, n-i) + s.substr(0, i);
        if (checkpal(temp)) {cout<<1; return 0;}

    }
    cout<<2;
    

}
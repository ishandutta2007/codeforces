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

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (s.length()>2||(s.length()==2&&s[0]<s[1]))
    {
        cout<<"YES"<<endl<<2<<endl;
        cout<<s[0]<<' ';
        for (int i = 1; i<s.length(); i++) cout<<s[i];
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for (int i = 0; i<n; i++) solve();

}
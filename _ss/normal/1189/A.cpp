#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
string s;
int n;
int main()
{
    cin>>n;
    cin>>s;
    int t1=0,t0=0;
    for (int i=0;i<n;i++)
        if (s[i]=='1') t1++; else t0++;
    if (t1==t0)
    {
        cout<<2<<endl;
        for (int i=0;i<n-1;i++) cout<<s[i];
        cout<<" "<<s[n-1];
    }
    else cout<<1<<endl<<s;
    return 0;
}
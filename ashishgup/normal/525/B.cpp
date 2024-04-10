#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
string s;
int flip[N];

int32_t main()
{
    IOS;
    cin>>s>>m;
    n=s.size();
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        flip[k]+=1;
    }
    for(int i=0;i<n/2;i++)
    {
        flip[i+1]+=flip[i];
        if(flip[i+1]%2)
            swap(s[i], s[n-1-i]);
    }
    cout<<s;
    return 0;
}
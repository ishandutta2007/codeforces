#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;

int main()
{
    int n,t=0,x;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        t=t | x;
    }
    if (!t) cout<<"EASY"; else cout<<"HARD";
    return 0;
}
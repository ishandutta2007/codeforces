#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n==1)
        {
            cout<<"-1\n";
            continue;
        }
        if ((n*2+1)%3!=0)
        {
            for (int i=1;i<n;i++) cout<<2;
            cout<<"3\n";
        }
        else
        {
            for (int i=1;i<n-1;i++) cout<<2;
            cout<<"33\n";
        }
    }
    return 0;
}
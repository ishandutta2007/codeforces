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
        ll d,m;
        cin>>d>>m;
        ll t=1,res=1;
        while (t<=d)
        {
            if (t*2>d) res=res*(d-t+2)%m;
            else res=res*(t+1)%m;
            t*=2;
        }
        cout<<(res-1+m)%m<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
 //   freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a>b+1 || d>c+1 || (a==b+1 && (d+c)!=0) || (d==c+1 && (a+b)!=0))
    {
        cout<<"NO";
        return 0;
    }
    if (a==b+1)
    {
        cout<<"YES\n";
        for (int i=1;i<=b;i++) cout<<"0 1 ";
        cout<<"0";
        return 0;
    }
    if (d==c+1)
    {
        cout<<"YES\n";
        for (int i=1;i<=c;i++) cout<<"3 2 ";
        cout<<"3";
        return 0;
    }
    if (abs((b-a)-(c-d))>1)
    {
        cout<<"NO";
        return 0;
    }
    if (b-a==c-d)
    {
        cout<<"YES\n";
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=b-a;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        return 0;
    }
    if (b-a>c-d)
    {
        cout<<"YES\n";
        cout<<"1 ";
        b--;
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=b-a;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        return 0;
    }
    if (c-d>b-a)
    {
        cout<<"YES\n";
        c--;
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=b-a;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        cout<<"2";
        return 0;
    }
    return 0;
}
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

string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        cin>>s;
        int check1=0,t=0,check3=0;
        for (int i=0;i<(int)s.length();i++)
        {
            if (s[i]=='0') check1++;
            else if (!((s[i]-'0')&1)) check3=1;
            t+=(s[i]-'0');
        }
        if (check1 && t%3==0 && (check3 || check1>1)) cout<<"red\n";
        else cout<<"cyan\n";
    }
    return 0;
}
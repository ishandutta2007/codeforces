#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=2e5+10;
char a[N];
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
        cin>>n>>(a+1);
        int cnt=0;
        for (int i=1;i<=n;i++) cnt+=a[i]-'0';
        if (cnt&1 || a[1]!='1' || a[n]!='1')
        {
            cout<<"NO\n";
            continue;
        }
        int sl=0,d1=0,d2=0;
        string s1,s2;
        for (int i=1;i<=n;i++)
            if (a[i]=='1')
            {
                ++sl;
                if (sl<=cnt/2)
                {
                    s1+='(';
                    s2+='(';
                    d1++;
                    d2++;
                }
                else
                {
                    s1+=')';
                    s2+=')';
                    d1--;
                    d2--;
                }
            }
            else
            {
                if (d1>=d2)
                {
                    s1+=')';
                    s2+='(';
                    d1--;
                    d2++;
                }
                else
                {
                    s1+='(';
                    s2+=')';
                    d1++;
                    d2--;
                }
            }
            cout<<"YES\n"<<s1<<"\n"<<s2<<"\n";
    }
    return 0;
}
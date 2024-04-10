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
const int N=1e5+10;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        vi vt1,vt2;
        for (int i=0;i<30;i++)
        {
            if ((u>>i)&1) vt1.eb(i);
            if ((v>>i)&1) vt2.eb(i);
        }
        int cnt=0,extra=0,check=1;
        int j=0,len=vt1.size();
        for (int x : vt2)
        {
            while (j<len && vt1[j]<x) j++,extra++;
            if (j<len && vt1[j]==x)
            {
                if (extra) cnt+=extra-1,extra=1;
                j++;
            }
            else
            {
                cnt+=extra;
                extra=0;
                if (cnt==0)
                {
                    check=0;
                    break;
                }
                else cnt--;
            }
        }
        if (check && j==len && extra==0) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
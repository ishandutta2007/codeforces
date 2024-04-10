#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#pragma GCC target("avx2")
 
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
const ll maxn=1e5,mod=1e9+7,inf=1e18;
bitset<maxn> a[26],c;
string s,y;
 
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for (int i=0;i<(int)s.length();i++) a[s[i]-'a'][i]=1;
    int q;
    cin>>q;
    for (int i=1,t;i<=q;i++)
    {
        cin>>t;
        if (t==1)
        {
            int v;
            char ch;
            cin>>v>>ch;
            if (s[v-1]==ch) continue;
            a[s[v-1]-'a'][v-1]=0;
            a[ch-'a'][v-1]=1;
            s[v-1]=ch;
        }
        else
        {
            int l,r,cnt;
            cin>>l>>r>>y;
            if ((int)y.size()>r-l+1)
            {
                cout<<"0\n";
                continue;
            }
            r-=y.size()-1;
            c=a[y[0]-'a'];
            for (int j=1;j<(int)y.length();j++) c&=a[y[j]-'a']>>j;
            c>>=l-1;
            cnt=c.count();
            c>>=r-l+1;
            cnt-=c.count();
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
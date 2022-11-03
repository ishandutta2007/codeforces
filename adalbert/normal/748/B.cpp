#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
///-----------------------------------------------------------------------///
set <pair <char,char> > setik;
char change [1000];
signed main()
{
    string st1,st2;
    cin>>st1>>st2;
    for (int i='a';i<='z';i++)
        change[i]=0;
    for (int i=0;i<st1.size();i++)
    {
        //cout<<st1[i]<<' '<<change[st1[i]]<<'!'<<st2[i]<<' '<<change[st2[i]]<<'\n';
        if (change[st1[i]]==0 && change[st2[i]]==st1[i]) change[st1[i]]=st2[i], change[st2[i]]=st1[i]; else
        if (change[st1[i]]==st2[i] && change[st2[i]]==0) change[st1[i]]=st2[i], change[st2[i]]=st1[i]; else
        if (change[st1[i]]==0 && change[st2[i]]==0) change[st1[i]]=st2[i], change[st2[i]]=st1[i]; else
        if (change[st1[i]]==st2[i] && change[st2[i]]==st1[i]) change[st1[i]]=st2[i], change[st2[i]]=st1[i]; else
        {
            cout<<-1;
            return(0);
        }
    }
    for (int i='a';i<='z';i++)
        if (change[i]!=i && change[i]!=0) setik.insert({min(change[i],(char)i),max(change[i],(char)i)});
    cout<<setik.size()<<'\n';
    for (auto i:setik)
        cout<<i.fir<<' '<<i.sec<<'\n';
}
#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef unsigned long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
ll cnt[1000];
int main()
{
    string st;
    cin>>st;
    char s;
    ll p=0,k=0;
    for (int i=0;i<st.size();i++)
        if (cnt[st[i]]==0) cnt[st[i]]=i+1; else

    {
        p=cnt[st[i]]-1;
        k=i;
        s=st[i];
    }
    ll kilk=(k-p);
    kilk--;
    if (kilk==0 )
    {
        cout<<"Impossible";
        return(0);
    }
    ll kv=kilk/2;
    ll kn=kilk-kv;
    string v="";
    v+=s;
    string n="";
    for (int i=p+1;i<=p+kv;i++)
        v+=st[i];
    for (int i=p+kv+1;i<k;i++)
        n+=st[i];
    reverse(v.begin(),v.end());
    ll i=k+1;
    i%=st.size();
    while (v.size()<13)
    {
        v+=st[i];
        i++;
        i%=st.size();
    }
    reverse(v.begin(),v.end());
    cout<<v<<'\n';
    string dop="";
     i%=st.size();
    while (n.size()+dop.size()<13)
    {
        dop+=st[i];
        i++;
        i%=st.size();
    }

    reverse(n.begin(),n.end());
    n=dop+n;
    cout<<n;

}
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define ld  long double
///-------------------///

ll k[100000];
string st;

///-------------------///





///---program start---///
int main()
{
    cin>>st;
    for (int i=0;i<st.size();i++)
        k[st[i]]++;
    if (k['a']==st.size())
    {
        st[st.size()-1]='z';
        cout<<st;
        return(0);
    }
    ll i=0;
    st+='a';
    while (st[i]=='a') i++;
    ll j=i;
    while (st[j]!='a') j++;
    //cout<<i<<' '<<j<<'\n';
    for (int l=i;l<j;l++) st[l]=st[l]-1;
    for (int i=0;i<st.size()-1;i++) cout<<st[i];
}
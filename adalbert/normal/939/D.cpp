#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[310000];

signed main()
{
    set<pair<int,int> > setik;
    int n;
    cin>>n;
    string st1,st2;
    cin>>st1>>st2;

    for (int i=0;i<st1.size();i++)
    {
        pair<int,int> now={st1[i],st2[i]};
        if (now.fir>now.sec)
            swap(now.fir,now.sec);
        setik.insert(now);
    }


    st1="";
    st2="";

    for (auto i:setik)
    {
        st1+=i.fir;
        st2+=i.sec;
    }

    setik.clear();


    for (int i=0;i<st1.size();i++)
        if (st1[i]!=st2[i])
    {
        char b=st2[i];
        char a=st1[i];
        if (a>b)
            swap(a,b);
        setik.insert({a,b});
        for (int j=0;j<st1.size();j++)
        {
            if (st1[j]==b)
                st1[j]=a;
            if (st2[j]==b)
                st2[j]=a;
        }
    }

    cout<<setik.size()<<'\n';
    for (auto i:setik)
        cout<<(char)i.fir<<' '<<(char)i.sec<<'\n';
}
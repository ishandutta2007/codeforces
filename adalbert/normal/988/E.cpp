#include<bits/stdc++.h>
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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5+100;

int x[arr];

int get(string st)
{
    int res=0;
    for (auto i:st)
    {
        res*=10;
        res+=i-'0';
    }
    return(res);
}

signed main()
{

    string st;
    cin>>st;

    if (st.size()==1)
    {
        cout<<-1;
        return(0);
    }

    pair<int,string> ans={1e9,""};

    for (int i=0;i<st.size();i++)
        for (int j=0;j<st.size();j++)
    {
        int p1=i;
        int p2=j;

        string now=st;
        int cnt=0;

        while (p2!=st.size()-1)
        {
            cnt++;
            swap(now[p2],now[p2+1]);
            p2++;
        }
        if (p1==st.size()-1)
        {
            swap(now[p1],now[p1-1]);
            p1--;
            cnt++;
        }
        while (p1!=st.size()-2)
        {
            cnt++;
            swap(now[p1],now[p1+1]);
            p1++;
        }

        int start=0;

        while (now[start]=='0')
            start++;

        while (start!=0)
        {
            swap(now[start],now[start-1]);
            start--;
            cnt++;
        }

        if (now[0]!='0' && get(now)%25==0)
        {
            ans=min(ans,{cnt,now});
        }
    }

    if (ans.fir==1e9)
        cout<<-1; else
        cout<<ans.fir;
}
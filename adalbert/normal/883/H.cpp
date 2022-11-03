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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"

int cnt[6000];
int last=0;

void change()
{
    if (last==3000)
        return;
    while (cnt[last]==0)
    {
        last++;
        if (last==3000)
            break;
    }
}

string reparse(string u)
{
    string res="";
    for (int i=0;i<u.size();i+=2)
        res+=u[i];
    reverse(res.begin(),res.end());
    for (int i=1;i<u.size();i+=2)
        res+=u[i];

    return(res);

}

signed main()
{
    int n;
    string st;
    cin>>n>>st;
    for (int i=0;i<st.size();i++)
        cnt[st[i]]++;

    vector<string> vec;

    for (int i=0;i<=5000;i++)
        if (cnt[i]%2)
    {
        cnt[i]--;
        n--;
        string now="";
        now+=i;
        vec.pb(now);
    }


    change();
    int add=0;

    if (vec.empty())
    {
        vec.pb({});
    }

    while (n%vec.size()!=0 || (n/vec.size()%2))
    {
        string now="";
        now+=last;
        vec.pb(now);
        n--;
        cnt[last]--;
        now="";
        now+=last;
        vec.pb(now);
        n--;
        cnt[last]--;
        change();
    }

    while (last!=3000)
    {
        cnt[last]-=2;
        vec[add]+=last;
        vec[add]+=last;
        add++;
        add%=vec.size();
        change();
    }

    cout<<vec.size()<<'\n';
    for (auto i:vec)
    {
        string now="";
        now=reparse(i);
        cout<<now<<' ';

    }
}
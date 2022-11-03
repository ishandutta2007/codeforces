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
#define files() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

int n;

int gt[5010][5010];

vector<int> get(int u)
{
    vector<int> res;
    res.pb(u);

    for (int i=1;i<n;i++)
    {
        res.pb(u^(gt[0][0]^gt[i][0]));
    }
    return(res);
}

vector<int> rev_(vector<int> vec)
{
    vector<int> res(vec.size());
    for (int i=0;i<vec.size();i++)
        res[vec[i]]=i;

    return(res);
}

bool check(vector<int> vec)
{
    for (int i=0;i<vec.size();i++)
        if (vec[i]>=n) return(0);
    vector<int> vec_=rev_(vec);

    for (int i=0;i<n;i++)
    {
        if ((vec[i]^vec_[0])!=gt[i][0]) return(0);
        if ((vec[0]^vec_[i])!=gt[0][i]) return(0);
    }
    //cout<<'!';
    sort(vec.begin(),vec.end());
    for (int i=1;i<vec.size();i++)
        if (vec[i]!=vec[i-1]+1)
        return(0);

    return(1);
}

signed main()
{

    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<'?'<<' '<<i<<' '<<0<<'\n';
        fflush(stdout);
        cin>>gt[i][0];
    }

    for (int i=0;i<n;i++)
    {
        cout<<'?'<<' '<<0<<' '<<i<<'\n';
        fflush(stdout);
        cin>>gt[0][i];
    }

    vector<int> ans;
    for (int i=0;i<n;i++)
    {
        vector<int> vec=get(i);


        if (check(vec))
            ans.pb(i);
    }
    cout<<'!'<<'\n';
    cout<<ans.size()<<'\n';
    vector<int> vec=get(ans[0]);
    for (auto i:vec)
        cout<<i<<' ';
    fflush(stdout);
}

/*
5 3
-4 -5 -3 -2 -1
*/

///https://ideone.com/eRRJ67
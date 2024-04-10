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
#define files(name) freopen("input.txt","r",stdin); freopen ("output.txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define int ll
#define endl "\n"

bool bad[1000000];
set<int> leavs;
int cnt=0;

void build(int i, int l, int r)
{
    cnt++;
    if (l+1==r)
    {
        bad[i]=1;
        leavs.insert(i);
        return;
    }
    int d=(l+r)/2;
    build(i*2,l,d);
    build(i*2+1,d,r);
}

vector<int> ans;

void solve(int i, int l, int r)
{
    if (bad[i])
    {
        for (int i=l;i<r;i++)
            ans.pb(i);
        return;
    }

    int d=(l+r)/2;
    int ln1=d-l;
    int ln2=r-d;
    solve(i*2,r-ln1,r);
    solve(i*2+1,l,l+ln2);
}

signed main()
{
    int n,k;
    cin>>n>>k;

    if (k%2==0)
    {
        cout<<-1;
        return(0);
    }

    build(1,0,n);

    if (k>cnt)
    {
        cout<<-1;
        return(0);
    }

    while (cnt>k)
    {
        cnt-=2;
        int now=*leavs.rbegin();
        if (now==1)
        {
            cout<<-1;
            return(0);
        }
        int pr=now/2;

        leavs.erase(pr*2);
        leavs.erase(pr*2+1);
        leavs.insert(pr);
        bad[pr]=1;
    }

    solve(1,0,n);

    for (int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<' ';
}
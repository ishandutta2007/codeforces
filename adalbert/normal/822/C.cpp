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
#define fir first
#define sec second
#define pb push_back
#define left einrdonbwrjnbo
#define right ejrngkeijvbr
#define pb push_back

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;

const int arr=3e5+10;
#define int ll

struct Node
{
    int l,r,cost;
};

map<int,int> mp;

bool check1(Node i, Node j)
{
    return(i.l<j.l);
}

bool check2(Node i, Node j)
{
    return(i.r<j.r);
}

Node a[arr],b[arr];

signed main()
{
    fast;
    int n,x;
    cin>>n>>x;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r>>a[i].cost;
        b[i].l=a[i].l;
        b[i].r=a[i].r;
        b[i].cost=a[i].cost;
    }

    sort(a+1,a+1+n,check1);
    sort(b+1,b+1+n,check2);
    b[n+1].r=1e9;
    int last=1;
    int ans=1e18;
    for (int i=1;i<=n;i++)
    {
        while (b[last].r<a[i].l)
        {
             mp[b[last].r-b[last].l+1]=max(mp[b[last].r-b[last].l+1],int(1e18)-b[last].cost);
            last++;
        }
        ans=min(ans,int(1e18)-mp[x-a[i].r+a[i].l-1]+a[i].cost);
    }
    if (ans>1e15) cout<<-1; else cout<<ans;
}
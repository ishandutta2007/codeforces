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

const int arr=9e5+10;
#define int ll

string st1,st2;
int n,m;
int get(int u)
{
    int res=0;
    for (int i=0;i<n;i++)
        if (st1[i]!=st2[i+u]) res++;
    return(res);
}

signed main()
{
    cin>>n>>m;
    cin>>st1>>st2;
    int mn=1e9;
    int imn=0;
    for (int i=0;i<=m-n;i++)
        if (get(i)<mn)
    {
        mn=get(i);
        imn=i;
    }
    cout<<mn<<'\n';
    for (int i=0;i<n;i++)
        if (st1[i]!=st2[i+imn])
        cout<<i+1<<' ';
}
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

int a[200000],smn[200000],pmn[200000];

signed main()
{
    int q;
    cin>>q;

    while (q--)
    {
        int n;
        cin>>n;
        if (n%4==0)
        {
            cout<<n/4<<'\n';
        } else
        if (n%4==1)
        {
            if (n<9)
                cout<<-1<<'\n'; else
                cout<<(n-9)/4+1<<'\n';
        } else
        if (n%4==2)
        {
            if (n<6)
                cout<<-1<<'\n'; else
                cout<<(n-6)/4+1<<'\n';
        } else
        if (n%4==3)
        {
            if (n<15)
                cout<<-1<<'\n'; else
                cout<<(n-15)/4+2<<'\n';
        }
    }
}

/*
5 3
-4 -5 -3 -2 -1
*/

///https://ideone.com/eRRJ67
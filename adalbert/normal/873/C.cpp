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

int a[200][200];

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];

    int rans=0;
    int rsht=0;


    for (int j=1;j<=m;j++)
    {
        int now_ans=0;
        int sht=0;
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int now=0;
            for (int l=i;l<=min(i+k-1,n);l++)
            {
                now+=a[l][j];
            }
            if (now>now_ans)
            {
                now_ans=now;
                sht=sum;
            }
            sum+=a[i][j];
        }
        //cout<<now_ans<<'\n';
        rans+=now_ans;
        rsht+=sht;
    }

    cout<<rans<<' '<<rsht<<'\n';
}
/*
15 3
1 2
2 3
1 7
*/
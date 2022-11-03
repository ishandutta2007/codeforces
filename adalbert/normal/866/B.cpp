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
#define int ll
struct Node
{
    int d,c,a,b;
};

const bool operator <(const Node i, const Node j)
{
    return(i.d<j.d);
}

int s[200000],a[200000],b[200000];

signed main()
{
    int n,cnt;
    cin>>n>>cnt;
    int all=0;
    vector<Node> vec;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i]>>a[i]>>b[i];
        sum+=s[i];
        vec.pb({a[i]-b[i],s[i],a[i],b[i]});
    }
    int ssum=sum;
    sum=(sum/cnt+(sum%cnt!=0))*cnt;
    int zal=sum-ssum;

    int left=0;
    int right=0;
    sort(vec.begin(),vec.end());

    for (int i=0;i<vec.size();i++)
        if (vec[i].d<=0) left+=vec[i].c;

    left=(left/cnt+(left%cnt!=0))*cnt;
    right=sum-left;
    int lll=left;
    int ans1=0;
    //cout<<left<<' '<<right<<' '<<zal<<'@'<<'\n';
    for (int i=0;i<vec.size();i++)
    {
        int cc=vec[i].c;
        if (left>zal)
        {
            int now=min(cc,left-zal);
            left-=now;
            cc-=now;
            ans1+=vec[i].b*now;
        }


        if (vec[i].d<=0)
        {
            ans1+=vec[i].b*min(cc,left);
            int now=min(cc,left);
            left-=now;
            ans1+=vec[i].a*(cc-now);
            right-=cc-now;
        } else
        {
            ans1+=vec[i].a*min(cc,right);
            int now=min(cc,right);
            right-=now;
            ans1+=vec[i].b*(cc-now);
            left-=(cc-now);
        }
    }

    int ans2=0;
    left=lll;
    if (left!=0)
        left-=cnt;
    right=sum-left;
    for (int i=0;i<vec.size();i++)
    {
        int cc=vec[i].c;
        if (left>zal)
        {
            int now=min(cc,left-zal);
            left-=now;
            cc-=now;
            ans2+=vec[i].b*now;
        }


        if (vec[i].d<=0)
        {
            ans2+=vec[i].b*min(cc,left);
            int now=min(cc,left);
            left-=now;
            ans2+=vec[i].a*(cc-now);
            right-=cc-now;
        } else
        {
            ans2+=vec[i].a*min(cc,right);
            int now=min(cc,right);
            right-=now;
            ans2+=vec[i].b*(cc-now);
            left-=(cc-now);
        }
    }
    cout<<max(ans1,ans2);
}
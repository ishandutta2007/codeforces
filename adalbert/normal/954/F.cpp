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
const int arr=6e5;

struct matrix
{
    int a[4][4];
    matrix(const matrix& cp)
    {
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            this -> a[i][j]=cp.a[i][j];
    }
    matrix()
    {

    }
};

matrix mult(matrix &a, matrix &b)
{
    matrix c;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            int now=0;
            for (int l=1;l<=3;l++)
            {
                now+=a.a[i][l]*b.a[l][j]%md;
                now%=md;
            }
            c.a[i][j]=now;
        }

    return(c);
}

matrix pow(matrix &a, int step)
{
    if (step==1) return(a);
    if (step%2==0)
    {
        matrix now=pow(a,step/2);
        return(mult(now,now));
    } else
    {
        matrix now=pow(a,step-1);

        return(mult(a,now));
    }
}

map <int,vector<int> > mp;

int get(int u, int i)
{
    return((u&(1<<i))!=0);
}

signed main()
{
    int n,m;
    cin>>n>>m;
    mp[2];
    mp[m];
    while (n--)
    {
        int i,l,r;
        cin>>i>>l>>r;
        mp[l].pb(i);
        mp[r+1].pb(-i);
    }

    int cnt1=0,cnt2=0,cnt3=0;

    vector<pair<int,int> > vec;

    for (auto i:mp)
    {
        for (auto j:i.sec)
        {
            if (j==1)
                cnt1++; else
            if (j==2)
                cnt2++; else
            if (j==3)
                cnt3++; else
            {
                j=-j;
                if (j==1)
                    cnt1--; else
                if (j==2)
                    cnt2--; else
                if (j==3)
                    cnt3--;
            }
        }
        int now=0;
        now+=(cnt1!=0);
        now+=2*(cnt2!=0);
        now+=4*(cnt3!=0);
        vec.pb({i.fir,now});
    }

    sort(vec.begin(),vec.end());

    int an1=0,an2=1,an3=0;
    for (int i=0;i+1<vec.size();i++)
    {
        matrix a;

        for (int ii=1;ii<=3;ii++)
            for (int j=1;j<=3;j++)
            if (abs(ii-j)<=1 && get(vec[i].sec,j-1)==0)
                a.a[ii][j]=1; else
                a.a[ii][j]=0;

        a=pow(a,vec[i+1].fir-vec[i].fir);


        int an11=a.a[1][1]*an1%md+a.a[2][1]*an2%md+a.a[3][1]*an3%md;
        int an22=a.a[1][2]*an1%md+a.a[2][2]*an2%md+a.a[3][2]*an3%md;
        int an33=a.a[1][3]*an1%md+a.a[2][3]*an2%md+a.a[3][3]*an3%md;
        an1=an11%md;
        an2=an22%md;
        an3=an33%md;
    }

    cout<<(an1+an2+an3)%md;
}
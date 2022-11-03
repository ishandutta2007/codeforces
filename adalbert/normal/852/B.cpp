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
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg
#define int ll
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;
typedef long double ld;
const int arr=2*1e6;

const int md=1e9+7;


struct matrix
{
    int a[100][100];
    matrix(const matrix& cp)
    {
        for (int i=0;i<100;i++)
            for (int j=0;j<100;j++)
            this -> a[i][j]=cp.a[i][j];
    }
    matrix()
    {

    }
};

matrix mult(matrix &a, matrix &b)
{
    matrix c;
    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
        {
            int now=0;
            for (int l=0;l<100;l++)
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

int dp[1000],dp2[1000],cnt[1000],pluss[1000];
int cost2[arr],cost1[arr];
signed main()
{
    fast;
    int n,l,m;
    cin>>n>>l>>m;

    for (int i=1;i<=n;i++)
    {
        cost1[i];
        cin>>cost1[i];
        cost1[i]%=m;
        dp[cost1[i]%m]++;
        dp[cost1[i]%m]%=md;
    }

    for (int i=1;i<=n;i++)
    {
        cost2[i];
        cin>>cost2[i];
        cost2[i]%=m;
        cnt[cost2[i]%m]++;
        cnt[cost2[i]%m]%=md;
    }

    matrix mat;

    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
        mat.a[i][j]=0;

    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
        {
            mat.a[i][(i+j)%m]+=cnt[j];
            mat.a[i][(i+j)%m]%=md;
        }





    l--;
    if (l-1!=0)
    {
        mat=pow(mat,l-1);
    } else
    {
        for (int i=0;i<100;i++)
            for (int j=0;j<100;j++)
                if (i!=j)
                mat.a[i][j]=0; else
                mat.a[i][j]=1;
    }




    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            dp2[j]+=dp[i]*mat.a[i][j]%md;




    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int cost;
        cin>>cost;
        cost%=m;
        ans+=dp2[(m-cost-cost2[i]+m)%m];
        ans%=md;
    }
    cout<<ans;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,i,j,r,l,a[5001],b[5001],lv[5001],pr[5001],mj[5001],kk[5001],p,mn,mx,mxj;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i=0; i<n; i++)cin >> a[i];
    cin >> m;
    for(i=0; i<m; i++)cin >> b[i];
    l=0;
    for(i=0; i<m; i++)
    {
        ll fl=0;
        r=l;
        p=0;
        mx=-1e9;
        mn=1e9;
        while(1)
        {
            p+=a[r];
            if(a[r]>mx)
            {
                mx=a[r];
                mxj=r;
            }
            mn=min(mn,a[r]);

            if(p==b[i])break;
            if(r>=n || p>b[i])
            {
                cout << "NO" << endl;
                return  0;
            }
            r++;
        }
        kk[i]=1;
        if(mn==mx and r-l>0)
        {
            cout << "NO" << endl;
            return  0;
        }
        if(mxj==l && r-l>0)
        {   ll xx=0;
            for(j=l;j<=r;j++)if(a[j]==mx && j!=r && a[j+1]<a[j]){mxj=j;break;}else if(a[j]==mx && j!=l && a[j-1]<a[j]){xx=1;mxj=j;break;}
            if(xx==0)kk[i]=2;
        }
        lv[i]=l+1;
        pr[i]=r+1;
        mj[i]=mxj+1;
        l=r+1;
    }
    if(r<n-1)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    for(i=m-1;i>=0;i--)
    {
        l=lv[i]; r=pr[i];
        //cout << lv[i] << " " << pr[i] << " " << mj[i] << endl;
         //if(n==500 && a[0]==398940)cout << kk[i] << endl;
        if(kk[i]==1)
        {
         for(j=mj[i];j>lv[i];j--)cout << j << " L" << endl;
         for(j=mj[i]+1;j<=r;j++)cout << lv[i]  << " R" << endl;
        }else
        {
         for(j=mj[i]+1;j<=r;j++)cout << mj[i] << " R" << endl;
         for(j=mj[i];j>lv[i];j--)cout << j << " L" << endl;
       }
    }
    return 0;
}
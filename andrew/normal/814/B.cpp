#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
using namespace std;
vector <ll> v[10001];
ll a[10001],b[10001],x1[10001],x2[10001],x[10001],p[100001],stn,i,j,k,n,m,sc,c;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll fl=0;
    ll c1=-1,c2=-1;
    for(i=0;i<n;i++){cin >> a[i];x[a[i]]++;x1[a[i]]++;}
    for(i=0;i<n;i++){cin >> b[i];x[b[i]]++;x2[b[i]]++;}
    for(i=1;i<=n;i++)if(x1[i]==0){c1=i;break;}
    for(i=1;i<=n;i++)if(x2[i]==0){c2=i;break;}
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            ll xx1=a[i],xx2=b[j];
            x1[a[i]]--;
            x2[b[j]]--;
            if(c1!=-1 and (x1[xx1]==0))
            {
                x1[xx1]++;
                x2[xx2]++;
                continue;
            }
            //cout << b[j] << endl;
            if(c2!=1 and x2[xx2]==0)
            {
                x1[xx1]++;
                x2[xx2]++;
                continue;
            }
            ll cc1,cc2;
            if(c1!=-1)cc1=c1; else cc1=xx1;
            if(c2!=1)cc2=c2; else cc2=xx2;
            p[i]=c1;
            p[j]=c2;
            if(i==j and c1==c2)
            {
           // cout << i << " " << j << endl;
                for(ll cc=0;cc<n;cc++)p[cc]=a[cc];
                p[i]=c1;
                for(ll cc=0;cc<n;cc++)cout << p[cc] << " ";
                return 0;
            }
            if(i==j)
            {

                x1[xx1]++;
                x2[xx2]++;
                continue;
            }
            if(a[j]!=p[j] or b[i]!=p[i])
            {
                x1[xx1]++;
                x2[xx2]++;
                continue;
            }
            for(ll cc=0;cc<n;cc++)p[cc]=a[cc];
            p[i]=c1;
            p[j]=c2;
            for(ll cc=0;cc<n;cc++)cout << p[cc] << " ";
                return 0;
        }
    return 0;
}
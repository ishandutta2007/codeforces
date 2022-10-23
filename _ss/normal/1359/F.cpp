#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
const double inf=4e19;
int X[N],Y[N],DX[N],DY[N],s[N],n,a[N],b[N],c[N],s2[N];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>X[i]>>Y[i]>>DX[i]>>DY[i]>>s[i];
}

void process()
{
    for (int i=1;i<=n;i++)
    {
        a[i]=DY[i];
        b[i]=-DX[i];
        c[i]=a[i]*X[i]+b[i]*Y[i];
        s2[i]=s[i]*s[i];
    }
    int d,flag1,flag2;
    double res=inf,x,y,dx,dy;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
        {
            d=a[i]*b[j]-a[j]*b[i];
            dx=c[i]*b[j];
            dx-=c[j]*b[i];
            dy=a[i]*c[j];
            dy-=a[j]*c[i];
            if (d==0)
            {
                if (dx==0)
                {
                    flag1=flag2=0;
                    if ((X[j]-X[i])*DX[i]>0) flag1=1;
                    if ((X[i]-X[j])*DX[j]>0) flag2=1;
                    double dis=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
                    if (flag1 && flag2) res=min(res,dis/((s[i]+s[j])*(s[i]+s[j])));
                    else if (flag1) res=min(res,dis/s2[i]);
                    else if (flag2) res=min(res,dis/s2[j]);
                }
                continue;
            }
            x=dx/d;
            y=dy/d;
            if ((x-X[i])*DX[i]<0 || (x-X[j])*DX[j]<0) continue;
            res=min(res,max(((x-X[i])*(x-X[i])+(y-Y[i])*(y-Y[i]))/s2[i],((x-X[j])*(x-X[j])+(y-Y[j])*(y-Y[j]))/s2[j]));
        }
    if (res==inf) cout<<"No show :(";
    else cout<<std::setprecision(15)<<sqrt(res);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}
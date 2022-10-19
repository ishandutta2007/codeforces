#include"bits/stdc++.h"
using namespace std;
/*
int mosolve(int m,int a,int b)
{
    ;
}
void check(long long a,long long b,double k)
{
    double q=1.0/k;
    long long n=log(b-a)/log(k)+1;
    long long money=a*(50-n);
    cout<<money<<endl;
    cout<<(long long)((1-pow(q,n))/(1-q)+1)+a*n<<endl;
}*/
#define ll long long
ll now;
ll maxs=1e14;
ll x1=0,x2=1e14+1;
int qnum;
void getmoney()
{
    cout<<"? "<<x1<<endl;
    now+=x1;
    string s;
    cin>>s;
    qnum--;
}int ct;
bool q(ll x)
{
    x=min(maxs,x);
    if(x>=x2)x=x2-1;
    if(x<=x1)x=x1+1;
    while(now<x)getmoney();
    cout<<"? "<<x<<endl;
    string s;
    cin>>s;
    qnum--;//cout<<"<<<<"<<ct<<endl;
    if(s[0]=='L')
    {
        x1=x;
        now+=x;
        ct++;
        return 1;
    }
    else
    {
        x2=x;
        now-=x;
        ct--;
        return 0;
    }
}
double iter[100];
void solve()
{
    qnum=105;
    now=1;
    x1=0;
    x2=1e14+1;
    ct=1;
    while(1)
    {
        if(now==70368744177664)break;
        bool ok=q(now);
        if(x1+1==x2)
        {
            cout<<"! "<<x1<<endl;
            return;
        }
        if(!ok)break;
    }ct=1;
    while(1)
    {
        //ll x=2/(1.0/x1+1.0/x2);
        //ll x=(100*x1+50*x2)/150;
        //ll x=1/(x1/(double)x2/now+1.0/now+1.0/x2);
        //ll g=now;
        //if(g<=x1)g+=x1;
        //ll x=min((2*g+x1+2)/3,(x1+x2)/2);
        ll x=(1-iter[ct])*x1+iter[ct]*x2;
        //x=min((x1+x2)/2,x);
        //ll x=x1;
        //ll x=(x1+x2)/2;
        //if(flag)x=(x1+x2)/2;
        //ll x=2/(1.0/x1+1.0/x2);
        //ll x=(x1+x2)/2;
        //printf("%.15f\n",2/(1.0/x1+1.0/x2));
        //printf("%lld\n",(x1+x2)/2);
        //*
        q(x);//*/
        if(x1+1==x2)
        {
            cout<<"! "<<x1<<endl;
            return;
        }/*
        x=min(maxs,x);
        if(x>=x2)x=x2-1;
        if(x<=x1)x=x1+1;
        bool flag=(now>=x2);
        flag=(x>=(80*x1+70*x2)/150);//flag=(x>99999999999996);
        while(now<x)getmoney();qnum--;cout<<qnum<<" "<<now<<" "<<x1<<" "<<x<<" "<<x2<<endl;
        if(flag)x2=x,now-=x,ct--;
        else x1=x,now+=x,ct++;
        //*/
        //if(((x2-x1)>>min(qnum-1,50)))break;
    }/*
    while(1)
    {
        ll x=(x1+x2)/2;
        q(x);
        if(x1+1==x2)
        {
            cout<<"! "<<x1<<endl;
            return;
        }
    }*/
}
int main()
{/*
    check(1ll<<49,1ll<<50,4);
    cout<<(1ll<<47)<<endl;
    cout<<(1ll<<46)<<endl;
    cout<<(1ll<<45)<<endl;
    cout<<pow(1.0/3,30)*3.5e13<<endl;
    cout<<pow(2.0/3,30)*3.5e13*pow(1.0/2,30)<<endl;
    cout<<pow(1.0/2,45)*3.5e13<<endl;
    cout<<pow(2.0/3,25)*3.5e13*pow(1.0/2,25)<<endl;*/
    iter[1]=1.0/4;
    for(int i=2;i<100;i++)
    {
        iter[i]=(iter[i-1]+0.5)/2;
    }
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*
1000
L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L L47
F1
L L L L L L L L L L L L L L L L L L L L L L L L L L26
F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F F35

*/

 #include<bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef long double lod;

const lol N=1000000;
const lol M=30000000;
const lol md=(1e9)+7;
const lol mx=(1e18);
const lol mn=(1e16);

#define F first
#define S second
#define fi first
#define se second
#define y1 yy1
#define sqr(a) ((a)*(a)

lol n,m,k,l,w,s,j,res,i,f[N],a[N],nex[N],p1,p2,pos,ch,x,e;

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("INVERSE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);

    srand(time(0));

    cin>>n>>x>>ch;
    if (n<=1999)
    {
        while (x>0)
        {
            cout<<"? "<<x<<endl;
            cin>>p1>>p2;
            if (p1>=ch) { cout<<"! "<<p1<<endl; return 0; }
            x=p2;
        }
        cout<<"! "<<-1<<endl;
        return 0;
    }
    for (i=1;i<=1000;i++)
    {
        s=(lol(rand())*lol(rand())*lol(rand())%n)+1;
        while (f[s]) s=(lol(rand())*lol(rand())*lol(rand())%n)+1;
        if (i==1) s=x;
        f[s]=1;
        cout<<"? "<<s<<endl;
        cin>>p1>>p2;
        k++; a[k]=p1; nex[k]=p2;
    }
    w=a[1];
    pos=nex[1];
    for (i=1;i<=k;i++) if (a[i]<=ch && a[i]>w) { w=a[i]; pos=nex[i]; }
    while (w<ch)
    {
        e++;
        if (e>1000) { cout<<"! -1"<<endl; return 0; }
        if (pos==-1) { cout<<"! -1"<<endl; return 0; }
        cout<<"? "<<pos<<endl;
        cin>>p1>>p2;
        w=p1;
        pos=p2;
    }
    if (w>=ch) cout<<"! "<<w<<endl; else cout<<"! -1"<<endl;
}
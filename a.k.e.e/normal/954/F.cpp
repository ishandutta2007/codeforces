#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=10005,MOD=1000000007;

int n;
ll p[MAXN<<4|1],S[5][MAXN<<4|1];
int ptot=0;
ll T;

inline int Abs(int x)
	{return x>0?x:-x;}

struct Block
{
	int a;
	ll l,r;
}d[MAXN];

struct Matrix
{
    ll a[5][5];
    int n,m;
    
    Matrix(int n=0,int m=0):n(n),m(m)
        {memset(a,0,sizeof(a));}
    
    void init()
    	{memset(a,0,sizeof(a));}
    void xtq()
    {
    	for(int i=1;i<=n;i++)
    		a[i][i]=1;
    }
    
    Matrix operator *(const Matrix &b)const
    {
        Matrix c(n,b.m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=b.m;j++)
                for(int k=1;k<=m;k++)
                    (c.a[i][j]+=a[i][k]*b.a[k][j])%=MOD;
        return c;
    }
    
    Matrix operator =(const Matrix &b)
    {
    	n=b.n;m=b.m;
		memcpy(a,b.a,sizeof(a));
	}
    
    void debug()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<a[i][j]<<" ";
            putchar('\n');
        }
        putchar('\n');
    }
}A,B;
/*
Matrix qmi(Matrix a,ll T)
{
    if(T==1)return a;
    if(T==2)return a*a;
    Matrix t=qmi(a,T>>1);
    if(T&1)return t*t*a;
    return t*t;
}
*/
Matrix qmi(Matrix a,ll T)
{
	Matrix ans(3,3);
	ans.xtq();
	for(int i=0;i<=60;i++)
	{
		if((1ll<<i)&T)
			ans=ans*a;
		a=a*a;
	}
	return ans;
}

Matrix getans(Matrix B,bool *v,ll len)
{
	A.n=A.m=3;
	A.init();
	for(int i=1;i<=3;i++)
	{
		if(v[i])continue;
		for(int j=i-1;j<=i+1;j++)
			A.a[j][i]=1;
	}
	//A.debug();
	return B*qmi(A,len);
}

inline int find(ll x)
	{return lower_bound(p+1,p+ptot+1,x)-p;}

bool vis[5];
int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u;
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
    	cin>>d[i].a>>d[i].l>>d[i].r;
    	if(d[i].l>1)p[++ptot]=d[i].l-1;
    	p[++ptot]=d[i].l;
    	if(d[i].l<T)p[++ptot]=d[i].l+1;
    	if(d[i].r>1)p[++ptot]=d[i].r-1;
    	p[++ptot]=d[i].r;
    	if(d[i].r<T)p[++ptot]=d[i].r+1;
    }
    p[++ptot]=T;
    p[++ptot]=1;
    sort(p+1,p+ptot+1);
    ptot=unique(p+1,p+ptot+1)-p-1;
    /*for(int i=1;i<=ptot;i++)
    	printf("%d ",p[i]);
    cout<<endl;*/
    for(int i=1;i<=n;i++)
    {
    	S[d[i].a][find(d[i].l-1)]--;
    	S[d[i].a][find(d[i].r)]++;
    }
    for(int j=1;j<=3;j++)
		for(int i=ptot-1;i>0;i--)
    		S[j][i]+=S[j][i+1];
    /*for(int j=1;j<=3;j++)
    {
    	for(int i=1;i<=ptot;i++)
    		printf("%d ",S[j][i]);
    	cout<<endl;
    }*/
    B.n=1;B.m=3;
    B.a[1][2]=1;
    //B.debug();
    for(int i=2;i<=ptot;i++)
    {
    	memset(vis,0,sizeof(vis));
    	for(int j=1;j<=3;j++)
    		if(S[j][i]>0)
    			vis[j]=true;
    	B=getans(B,vis,p[i]-p[i-1]);
    	//B.debug();
    }
    cout<<B.a[1][2]<<endl;
    return 0;
}
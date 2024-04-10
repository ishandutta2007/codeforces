#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=301*1000;
ll MOD=((ll)1e9+9);
const ll INF=((ll)1e9);

struct Mat{
	ll n,m,a[10][10];
	Mat(){
		n=6;
		m=6;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				a[i][j]=0;
	}
	Print(){
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<a[i][j];
			cout<<"\n";
		}
	}
};

Mat operator *(const Mat &a,const Mat &b)
{
	Mat ans;
	for(int i=0;i<a.n;i++)
		for(int j=0;j<b.m;j++)
			for(int k=0;k<a.m;k++)
				ans.a[i][j]+=a.a[i][k]*b.a[k][j],ans.a[i][j]%=MOD,ans.a[i][j]+=MOD,ans.a[i][j]%=MOD;
	return ans;
}

Mat power(Mat p,ll k)
{
	Mat ans;
	for(int i=0;i<6;i++)ans.a[i][i]=1;
	while(k)
	{
		if(k%2)ans=ans*p;
		k/=2;
		p=p*p;
	}
	return ans;
}

ll n,x,y,dx,dy,t;
Mat ex;
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y>>dx>>dy>>t;
	x--;y--;
	MOD=n;
	ex.a[0][0]=ex.a[1][1]=ex.a[0][5]=ex.a[1][5]=ex.a[2][5]=ex.a[3][5]=2;
	ex.a[0][1]=ex.a[0][2]=ex.a[0][4]=
	ex.a[1][0]=ex.a[1][3]=ex.a[1][4]=
	ex.a[2][0]=ex.a[2][1]=ex.a[2][2]=ex.a[2][4]=
	ex.a[3][0]=ex.a[3][1]=ex.a[3][3]=ex.a[3][4]=
	ex.a[4][4]=ex.a[4][5]=
	ex.a[5][5]=1;
	Mat p=power(ex,t);
	//p.Print();
	Mat q;q.m=1;
	q.a[0][0]=x;q.a[1][0]=y;q.a[2][0]=dx;q.a[3][0]=dy;q.a[4][0]=0;q.a[5][0]=1;
	//q.Print();
	p=p*q;
	//p.Print();
	cout<<p.a[0][0]+1<<" "<<p.a[1][0]+1<<"\n";
	return 0;
}
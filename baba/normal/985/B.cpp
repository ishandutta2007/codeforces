/*	Sreya Mittal
	IIIT-Hyderabad	*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mi 1000000007
#define fastScan ios_base::sync_with_stdio(0); 
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=a;i>b;i--)
#define pb push_back
#define mp make_pair
#define let(x,a) __typeof(a) x(a)
#define tr(v,it) for(let(it,v.begin()); it != v.end(); it++)
#define SET(a,b) memset(a,b,sizeof(a))

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int mult(int x,int y)
{
	ll ans,x1=(ll)x,y1=(ll)y;
	ans=(x1*y1)%mi;
	return (int)ans;
}
int gcd(int a,int b) { return b==0 ? a : gcd (b,a%b);}
int lcm(int a,int b) { return a*(b/gcd(a,b));}

int pow1(int a,int b)
{
	int ans=1;
	while(b>0) {
		if(b&1) ans=mult(ans,a);  
		a=mult(a,a); b>>=1;
	} 
	return ans;
}
	vector<int> lamp_switch[2001];
	vector<int> switch_lamp[2001];
	int a[2001][2001];
int main()
{
	int n, m, i, j, flag;
	char x;
	cin >> n >> m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>x;
			a[i][j]=x-'0';
			if(x=='1')
			{
				lamp_switch[j].push_back(i);
				switch_lamp[i].push_back(j);
			}
		}
	}

	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<switch_lamp[i].size();j++)
		{
			if(lamp_switch[switch_lamp[i][j]].size()==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==0) 
		{
			break;
		}
	}
	if(flag==0) cout <<"YES\n";
	else cout<<"NO\n";
	return 0;
}
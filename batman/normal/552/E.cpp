//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.3 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll ans;
string s;
vector <ll> in1,in2;

ll calc(ll l,ll r)
{
	/*
	if(r==3)
		cerr<<"khar"<<endl;
		*/
	ll tmp1=0,tmp2=s[l]-'0';
	for(int i=l+1;i<r;i+=2)
	{
		if(s[i]=='*')
			tmp2*=s[i+1]-'0';
		else
			tmp1+=tmp2,tmp2=s[i+1]-'0';	
	}
	tmp1+=tmp2;
	string p="";
	for(int i=0;i<l;i++)
		p+=s[i];
	p+='x';
	for(int i=r;i<s.size();i++)
		p+=s[i];
	tmp2=0;
	ll tmp3=p[0]-'0';
	if(l==0)
		tmp3=tmp1;	
	for(int i=1;i<p.size();i+=2)
	{
		if(p[i]=='*')
			tmp3*=(p[i+1]=='x')?tmp1:p[i+1]-'0';
		else
			tmp2+=tmp3,tmp3=p[i+1]-'0';	
	}		
	return tmp2+tmp3;
}

int Sa1378
{ 
    IB
   	cin>>s;
   	in1.PB(0);
   	in2.PB(s.size());
   	for(int i=0;i<s.size();i++)
   		if(s[i]=='*')
   			in1.PB(i+1),in2.PB(i);
   	for(int i=0;i<in1.size();i++)
	   	for(int j=0;j<in2.size();j++)
	   		if(in1[i]<in2[j])
	   			ans=max(ans,calc(in1[i],in2[j]));
	cout<<ans;		   	
    return 0;
}
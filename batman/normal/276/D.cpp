//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.6 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (201*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI (ld)(3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)

ifstream fin("input.txt");
ofstream fout("output.txt");
bool bit[2][10000];
ll a,b,p,q;
int Sa1378
{ 
	IB
   	scanf("%I64d %I64d",&a,&b);
   	if(b>a)
   		swap(a,b);
	while(a)
	{
		bit[0][p++]=(a%2);
		a/=2ll;
	}   	
	while(b)
	{
		bit[1][q++]=(b%2);
		b/=2ll;
	}	
	/*	
	for(int i=bit[0].size()-1;i>=0;i--)
		cout<<bit[0][i];
	cout<<endl;
	for(int i=bit[0].size()-1;i>=0;i--)	
		cout<<bit[1][i];
	cout<<endl;	
	*/	
	
	for(ll i=max(p,q)-1;i>=0;i--)
		if(bit[0][i]==1 && bit[1][i]==0)
		{
			ll ans=1;
			for(int j=0;j<=i;j++)ans*=2;
			printf("%I64d",ans-1);
			return 0;
		}
	cout<<0;		
				
    return 0;
}
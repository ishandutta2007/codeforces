    //||||||||||||||||||||||||||||||||||||\\
   //||||Sa1378 Platform Vesion 1.3.8.5||||\\
  //||||||||||||||||||||||||||||||||||||||||\\

//The cycle that never ends
	//It begins and starts again
		//Trapped like mice inside a maze
			//And bereft of our own grace...

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cout << #x << " is " << x << endl;
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define sin(a) sin(a*PI/180)
#define tan(a) tan(a*PI/180)
#define cot(a) cot(a*PI/180)
#define cos(a) cos(a*PI/180)
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
inline ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ld tavan(ld a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
ifstream fin("input.txt");
ofstream fout("output.txt");
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll BIG_HSH=((ll)9999999900000001);
const ll SML_HSH=((ll)100030001);
const ll N =301*1000;

ll n,t,p,cnt;
string s1,s2,ans;

int Sa1378
{
    IB
    cin>>n>>t>>s1>>s2;
    ans=s1;
    for(int i=0;i<n;i++)
    {
    	//cout<<1<<endl;
    	if(s1[i]==s2[i])ans[i]=s1[i];
    	else
    	{
    		ans[i]='a';
    		if(ans[i]==s1[i] || ans[i]==s2[i])
    			ans[i]='b';
    		if(ans[i]==s1[i] || ans[i]==s2[i])
    			ans[i]='c';	
    		cnt++;	
		}
	}
	if(cnt<t)
	{
		//cout<<2<<endl;
		for(int i=0;i<n && cnt<t;i++)
			if(s1[i]==s2[i])
			{
				cnt++;
					ans[i]='a';
    			if(ans[i]==s1[i] || ans[i]==s2[i])
    				ans[i]='b';
			}
	}
    else
    {
    	//cout<<3<<endl;
    	ll x[2]={cnt,cnt};
    	bool m=0;
    	for(int i=0;i<n && (x[0]>t || x[1]>t);i++)
			if(s1[i]!=s2[i])
			{
				x[m]--;
				if(m==0)
					ans[i]=s1[i],m=1;
				else
					ans[i]=s2[i],m=0;	
			}
		if(x[0]>t || x[1]>t)
			return cout<<-1,0;
				
	}
	cout<<ans;
    return 0;
}
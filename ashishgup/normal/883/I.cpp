#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>
 
#define vi vector<int> 
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >   
#define vpl vector< pair<ll,ll> >   
typedef pair<pair<int, ll>,int> P;
 #define mod %1000000007
 #define p 41
bool less_vectors(const vector<int>& a,const vector<int>& b) 
{
   return a.size() > b.size();
}
 
ll gcd(ll a,ll b)
{
if(a%b==0)
   return b;
   else
        return gcd(b,a%b);
}
class compr
{
   public:
bool operator()(pair<pair<int,ll>,int>  p1,pair<pair<int,ll>,int> p2)
{
   if(p1.ff.ss!=p2.ff.ss)
        return p1.ff.ss>p2.ff.ss;
        else
             if(p1.ss!=p2.ss)
             return p1.ss>p2.ss;
             else
                  return p1.ff<p2.ff;
             
}

};
ll fastexpo(ll a,ll b)
{
   //trace2(a,b);
   ll res=1;
   while(b>0)
   {
        if(b%2==1)
             res=(((res)mod)*((a)mod))mod;
        a=(((a)mod)*((a)mod))mod;
        b/=2;
   }
   //trace1(res);
   return res;
}
ll fastexpom(ll a,ll b,ll m)
{
ll res=1;
   while(b>0)
   {
        if(b%2==1)
             res=(((res)%m)*((a)%m))%m;
        a=(((a)%m)*((a)%m))%m;
        b/=2;
   }
   return res;
}
ll modinv(ll a,ll m=1000000007)
{
return fastexpom(a,m-2,m);
}


int main()
{
		IOS;
		#ifndef ONLINE_JUDGE
		freopen("int.txt","r",stdin);
		freopen("out.txt","w",stdout);
		#endif
		ll n,s,l,k;
		cin>>n>>k;
		//s-differnce l-minimum number of numbers
		vi v(n);
		for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
		ll lo=0;
		ll hi=2e9;
		while(lo<hi)
		{
			ll mid=(lo+hi)>>1;
		//	trace3(lo,mid,hi);
			s=mid;
			l=k;
		deque<int> dqmax,dqmin;
		vi f(n,2000000001);
		vi g(n);
		int tail=0;
		g[0]=0;
		dqmax.pb(0);
		dqmin.pb(0);
		for(int i=1;i<n;i++)
		{
		while(!dqmax.empty() && v[dqmax.back()]<v[i])
		  dqmax.pop_back();
		dqmax.pb(i);
		while(!dqmin.empty() && v[dqmin.back()]>v[i])
		  dqmin.pop_back();
		dqmin.pb(i);
		while(!dqmin.empty() && !dqmax.empty() && v[dqmax.front()]-v[dqmin.front()]>s)
		{
		  //trace3(i,v[dqmax.front()],v[dqmin.front()]);
		  ++tail;
		  if(dqmax.front()<tail)
		    dqmax.pop_front();
		  if(dqmin.front()<tail)
		    dqmin.pop_front();
		}
		g[i]=tail;
		// trace2(i,g[i]);
		}
		//trace2(mid,g[l-1]);
		if(g[l-1]>0)
        {
          lo=mid+1;
          //return 0;
        }
        else
          f[l-1]=1;
		//f[l-1]=1;
		deque<pair<int,int> > dq;
		dq.pb(mp(0,-1));
		//trace1(f[1]);;
		for(int i=l;i<n;i++)
		{
		//trace4(dq.front().ss,dq.front().ff,dq.back().ss,dq.back().ff);
		while(!dq.empty() && dq.back().ff>=f[i-l])
		  dq.pop_back();
		//trace3(i,f[i-l],i-l);
		dq.pb(mp(f[i-l],i-l));
		while(!dq.empty() && dq.front().ss<g[i]-1)
		  dq.pop_front();

		if(!dq.empty())
		  f[i]=dq.front().ff+1;
	//	trace2(i,f[i]);
		}


			//trace1(n/k);
		//trace2(n/k,f[n-1]);
				if(f[n-1]>n/k)
					lo=mid+1;
				else
					hi=mid;
				//trace2(lo,hi);
				//cout<<f[n-1];
		
	}
	cout<<lo;
return 0;
}
// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int comp(string &s,string &t)
{
	vi a,b;
	// deb(s)
	// deb(t)
	fi(s.size()){
		if(s[i]!=t[i])
		{
			if(s[i]=='0')
			{
				a.pb(i);
			}
			else b.pb(i);
		}
	}
	int ans=0;
	if(a.size()==b.size()){
		fi(a.size())ans+=abs(a[i]-b[i]);
	}
	else return inf;
	return ans;
}
 
int32_t main()
{
	int t;cin>>t;
	while(t--)
	{
		int ev=0,od=0;
		int n;cin>>n;
		vi a(n);
		fi(n)
		{
			cin>>a[i];
			if(a[i]%2)od++;
			else ev++;
			a[i]=a[i]%2;
		}		
		if(abs(od-ev)>1)cout<<-1<<endl;
		else{
			string s="";
			string s1="",s2="";
			fi(n)
			{
				s+=to_string(a[i]);
				if(i%2){
					s1+="0";
					s2+="1";
				}
				else{
					s1+="1";
					s2+="0";
				}

			}
			int ans=comp(s,s1);
			ans=min(ans,comp(s,s2));
			cout<<ans<<endl;

		}
	}
}

int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}
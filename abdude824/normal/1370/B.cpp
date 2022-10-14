// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// (`v)
// `..Coding
//  `
// 
// 
// 
// 
// ``
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include<bits/stdc++.h>

using namespace std;

#define int long long int
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

void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
// 	aeh();
	W(t)
	{
		int n;
		cin>>n;
		vi a(2*n);
		fi(2*n)
		cin>>a[i];
		vi od,ev;
		fi(2*n)
		{
		    if(a[i]%2)
		    {
		        od.pb(i);
		    }
		    else
		    ev.pb(i);
		}
		int b=od.size();
		int c=ev.size();
		if(b%2&&c%2)
		{
		  //  cout<<od[0]+1<<" "<<ev[0]+1<<endl;
		    fi(b)
		    {
		        if(i!=0){
		            cout<<od[i]+1<<" "<<od[i+1]+1<<endl;
		            i++;
		        }
		    }
		    fi(c)
		    {
		        if(i!=0)
		        {
		            cout<<ev[i]+1<<" "<<ev[i+1]+1<<endl;
		            i++;
		        }
		    }
		}
		else{
		  //  if(b>=2)
		  //  cout<<od[0]+1<<" "<<od[1]+1<<endl;
		  //  else
		  //  cout<<ev[0]+1<<" "<<ev[1]+1<<endl;
		    if(b>=2)
		    {
    		    fo(i,2,b)
    		    {
    		        cout<<od[i]+1<<" "<<od[i+1]+1<<endl;
    		        i++;
    		    }
    		    fo(i,0,c)
    		    {
    		        cout<<ev[i]+1<<" "<<ev[i+1]+1<<endl;
    		        i++;
    		    }
		    }
		    else{
		        fo(i,0,b)
    		    {
    		        cout<<od[i]+1<<" "<<od[i+1]+1<<endl;
    		        i++;
    		    }
    		    fo(i,2,c)
    		    {
    		        cout<<ev[i]+1<<" "<<ev[i+1]+1<<endl;
    		        i++;
    		    }
		    }
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
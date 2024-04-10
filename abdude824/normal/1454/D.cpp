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


/*       *********
 *       *
 *   *   *   *
 *       *
 *****************
         *       *
     *   *   *   *
         *       *
 *********       */
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

// A function to print all prime 
// factors of a given number n 
void primeFactors(int n) 
{ 
	vi res;
	// Print the number of 2s that divide n 
	while (n % 2 == 0) 
	{ 
		res.pb(2);
		n = n/2; 
	} 

	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		// While i divides n, print i and divide n 
		while (n % i == 0) 
		{ 
			res.pb(i);
			n = n/i; 
		} 
	} 

	// This condition is to handle the case when n 
	// is a prime number greater than 2 
	if (n > 2){
		res.pb(n);
	} 
	vi fin;
	int curr=1;
	int fl=0;
	map<int,int>b;
	for(int i=0;i<res.size();i++)
	{
		b[res[i]]++;
	}
	int mx=-1;
	int rep;
	for(auto it:b)
	{
		if(mx<it.s)
		{
			mx=it.s;
			rep=it.f;
		}
	}
	cout<<mx<<endl;
	for(int i=0;i<mx-1;i++)
		cout<<rep<<" ";
	int cur=rep;
	fi(res.size())
	{
		if(res[i]!=rep)
		{
			cur*=res[i];
		}
	}
	cout<<cur;
	cout<<endl;
} 

int32_t main()
{
	aeh();
	int t;cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		primeFactors(n);
	}
}
// // Driver Code 
// int main()  
// {  
//     char X[] = "AGGTAB";  
//     char Y[] = "GXTXAYB";  
      
//     int m = strlen(X);  
//     int n = strlen(Y);  
      
//     cout << "Length of LCS is " 
//          << lcs( X, Y, m, n );  
      
//     return 0;  
// }  

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
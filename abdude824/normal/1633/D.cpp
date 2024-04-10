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
#define setbits(x) __builtin_popcnttll(x)
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
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int steps[1001];
int knapSack(int W, vi &wt, vi &val, int n)
{
	int i, w;
	int K[2][W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i % 2][w] = 0;
			else if (wt[i - 1] <= w)
				K[i % 2][w] = max(
					val[i - 1]
					+ K[(i - 1) % 2][w - wt[i - 1]],
					K[(i - 1) % 2][w]);
			else
				K[i % 2][w] = K[(i - 1) % 2][w];
		}
	}
	return K[n % 2][W];
}
int countMovesToConvert(int z)
{
	int cnt=0;
	int x=1;
	while(x!=z)
	{
		int y=x/(z-x);
		if(x%(z-x))y++;
		y=max(y,1ll);
		x=x+(x/y);
		cnt++;
	}
	return cnt;
}
vi getValueArray(vi &b)
{
	vi a(b.size(),0);
	fi(b.size())a[i]=steps[b[i]];
	return a;
}
int32_t main()
{
	aeh();
	int t;cin>>t;
	int mxn = 1001;
	for(int i=0; i<mxn; i++) steps[i]=-1;
		steps[1] = 0;

	for(int i=1; i<mxn; i++){
        if(steps[i]==-1) continue; // not possible
        for(int x=1; x<=i; x++){
        	int val = i + (i/x);
        	if(val>=mxn) continue;
        	if(steps[val]==-1) steps[val]=steps[i]+1;
        	else{
        		steps[val] = min(steps[val], steps[i]+1);
        	}
        }
		 }
	while(t--)
	{	
		int n,W;
		cin>>n>>W;
		vi b(n);
		fi(n)cin>>b[i];
		vi val(n);
		fi(n)cin>>val[i];
	    vi wt=getValueArray(b);

	    vi val2,wt2;
	    int ans=0;
	    int wt_sum=0;
	    fi(n)
	    {
	    	if(wt[i]){
	    		val2.pb(val[i]);
	    		wt_sum+=wt[i];
	    		wt2.pb(wt[i]);
	    	}
	    	else
	    		ans+=val[i];
	    }
	    W=min(W,wt_sum);
			// fi(val2.size())cout<<wt2[i]<<" ";
			// cout<<"\n";
	    ans+=knapSack(W, wt2, val2, wt2.size());
	    cout<<ans<<endl;
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
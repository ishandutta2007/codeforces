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
vector<pair<int,int>> merge(vector<pair<int,int>>& intervals) {
        //base case
        if(intervals.size()<=1) return intervals;
        //resultan vector
        vector<pair<int,int>> result;
        //sort takes O(nlogn) time
        sort(intervals.begin(), intervals.end()); 
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
         //Traverse the whole vector .Takes O(n) time
        for(int i=1; i<intervals.size(); i++) {
             //if intevals are overlapping
            if(result.back().s >= intervals[i].f) result.back().s = max(result.back().s , intervals[i].s);
            //else they are not overlapping
            else result.push_back(intervals[i]); 
        }
        return result;
    }
int32_t main()
{
    aeh();
    int t;cin>>t;
    while(t--)
    {
    	// brute force: a time array, and har time ke liye filling us array ko and last mei usi array ka sum
    	// 9-2+1
    	// 5 7 3
    	// 2 2 1

    	// 4,5 7,7 8,9

    	// [{2,5},{2,7},{1,3}]

    	// [{1,7}]


    	int n;cin>>n;
    	vi a(n),b(n);

    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		cin>>b[i];
    	}
    	
    	vi c(n);
    	fi(n)
    	{
    		c[i]=a[i]-b[i]+1;
    	}
    	vpi d;
    	fi(n)
    	{
    		d.pb({c[i],a[i]});
    	}
    	sortall(d);

    	d=merge(d);
    	// for(auto it:d)cout<<it.f<<": "<<it.s<<endl;
    	int cnt=0;
    	for(int i=0;i<d.size();i++)
    	{
    		int power=d[i].s-d[i].f+1;
    		cnt+=(power*(power+1))/2;
    	}
    	cout<<cnt<<endl;
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
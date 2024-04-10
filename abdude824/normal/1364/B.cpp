#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define chlo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()
#define sortall(x) sort(all(x))
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define F first
#define S second
#define pii pair<int,int>

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
//Chliye Backchodi shuru kren

int32_t main()
{
    W(t)
    {
        int n;
        cin>>n;
        vi a(n);
        fi(n)
        cin>>a[i];
        int as=n;
        int y=0;
        for(int i=1;i<n-1;i++)
        {
            int csum=abs(a[i]-a[y])+abs(a[i]-a[i+1]);
            int psum=abs(a[i+1]-a[y]);
            if(psum>=csum)
            {
                // a.erase(a.begin()+i);
                a[i]=-1;
                as--;
            }
            else
            {
                y=i;
            }
        }
        cout<<as<<endl;
        fi(n){
            if(a[i]!=-1)
            cout<<a[i]<<" ";
        }
        cout<<endl;
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
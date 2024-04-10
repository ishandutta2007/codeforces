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
int isPossible(int key,vi a,int n,int s)
{
    // deb(key)
    int cnt=0;
    int rem=n-(s/key);
    fi(n)
    {
        if(a[i]>key)
            return -1;
        if(a[i]!=key)
        {
            if(rem==0)
                return -1;
            if(i==n-1)
                return -1;
            rem--;
            cnt++;
            a[i+1]+=a[i];
        }
    }
    return cnt;
}
int32_t main()
{
    aeh();
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vi a(n);
        fi(n)
        cin>>a[i];
        int ans=n-1;
        set<int> pos;
        int s=0;

        fi(n)
        s+=a[i];

        for(int i=1;i<=sqrt(s);i++)
        {
            if(s%i==0)
            {
                pos.insert(i);
                pos.insert(s/i);
            }
        }

        for(auto it:pos)
        {
            int kk=isPossible(s/it,a,n,s);
            if(kk!=-1){

                ans=min(ans,kk);
            }
        }

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
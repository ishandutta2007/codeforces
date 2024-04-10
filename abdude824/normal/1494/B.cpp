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
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool check(int u, int d, int l, int r, int n)
{
    if(u == 1 || d == 1)
    {
        if(l == n && r == n)
        {
            return 0;
        }
    }
    if(u == 0 || d == 0)
    {
        if((l + r) > ( 2 * n - 2))
        {
            return 0;
        }
        if(u == 1 || d == 1)
        {
            if((l + r) > (2 * n - 3))
            {
                return 0;
            }
        }
    }
    if(u == 0 && d == 0)
    {
        if((l + r) > ( 2 * n - 4))
        {
            return 0;
        }
    }
    if(u == 1 && d == 1)
    {
        if((l + r) > (2 * n - 2))
        {
            return 0;
        }
    }
    return 1;
}
string convertToBinary(int n)
{
    string s="";
    while (n > 0) { 
  
        // storing remainder in binary array 
        s += to_string(n % 2); 
        n = n / 2; 
    } 
    while(s.size()!=4)
        s+="0";
    reverse(all(s));
    return s;
}
int32_t main()
{
    aeh();
    int t;
    cin >> t;
    while(t--)
    {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        int fl=0;
        fi(16)
        {
            int ru, lu, rd, ld;
            string s = convertToBinary(i);

            int u1 = u, r1 = r, d1 = d, l1 = l;
            ru = s[0] - '0';
            lu = s[1] - '0';
            rd = s[2] - '0';
            ld = s[3] - '0';
            
            if(ru)
            {
                r--;
                u--;
            }
            if(lu)
            {
                l--;
                u--;
            }
            if(rd)
            {
                d--;
                r--;
            }
            if(ld)
            {
                l--;
                d--;
            }
            if(r < 0 || u < 0 || l < 0 || d < 0 || r > n - 2 || d > n - 2 || u > n - 2 || l > n - 2)
            {
                u=u1;r=r1;l=l1;d=d1;
                continue;
            }
            else
            {
                fl = 1;
                break;
            }

        }
        if(fl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

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
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

int32_t main()
{
    aeh();
    int r;
    int c;
    cin >> r >> c;
    char a[r + 2][c + 2];
    fi(r)
    {
        fj(c)
        cin >> a[i + 1][j + 1];
    }
    int fl = 0;
    fi(r + 1)
    {
        fj(c + 1)
        {
            if(a[i][j] == 'S')
            {

                if(a[i][j + 1] == 'W' || a[i + 1][j] == 'W' || a[i - 1][j] == 'W' || a[i][j - 1] == 'W')
                {
                    fl = 1;
                    i = r;
                    break;
                }
                if(a[i][j + 1] != 'S')
                    a[i][j + 1] = 'D';
                if(a[i + 1][j] != 'S')
                    a[i + 1][j] = 'D';
                if(a[i][j - 1] != 'S')
                    a[i][j - 1] = 'D';
                if(a[i - 1][j] != 'S')
                    a[i - 1][j] = 'D';

            }
        }

    }
    if(!fl)
    {
        cout << "YES\n";
        fi(r)
        {
            fj(c)
            cout << a[i + 1][j + 1] << "";
            cout << endl;
        }
    }
    else
        cout << "NO\n";
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
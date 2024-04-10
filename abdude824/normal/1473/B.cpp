
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
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool subset(string s, string p)
{
    if(s.size() < p.size())
        swap(s, p);
    if(s.size() % p.size())
        return 0;
    else
    {
        fi(s.size() - p.size() + 1)
        {
            fj(p.size())
            {
                if(p[j] != s[i + j])
                {
                    return 0;
                }
            }
            i += p.size() - 1;
        }
        return 1;
    }

}
int32_t main()
{
    aeh();
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string p;
        cin >> p;
        if(subset(s, p))
        {

            s = s.size() > p.size() ? s : p;
            cout << s << endl;
        }
        else
        {
            if(s.size() < p.size())
                swap(s, p);
            set<char>a;
            set<char>b;
            fi(s.size())
            {
                a.insert(s[i]);
            }
            fi(p.size())
            {
                b.insert(p[i]);
            }
            if(a.size() == b.size())
            {
                int ffl=1;
                for(int i = 0; i < p.size(); i++)
                {
                    if(p[i] != s[i])
                    {
                        ffl=0;
                        break;
                    }
                }
                int j=0;
                for(int i=p.size();i<s.size();i++)
                {
                    if(p[j]!=s[i])
                    {
                        ffl=0;
                        break;
                    }
                    j++;
                    if(j==p.size())
                        j=0;
                }
                j=p.size()-1;
                for(int i=s.size()-1;i>=0;i--)
                {
                    if(p[j]!=s[i])
                        ffl=0;
                    j--;
                    if(j==-1)
                        j=p.size()-1;
                }
                if(ffl&&s[s.size()-1]==p[p.size()-1])
                {
                    string q=p;
                    while(!subset(q,s))
                    {
                        q+=p;
                    }
                    cout<<q<<endl;
                }
                else
                    cout << -1 << endl;
            }
            else
                cout<<-1<<endl;

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
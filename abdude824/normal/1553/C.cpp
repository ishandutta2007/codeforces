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
void make_teams(string &s, string &a, string &b)
{
    fi(s.size())
    {
        if (i % 2)
            b += s[i];
        else
            a += s[i];
    }
}
void win(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')s[i] = '1';
    }
}
void lose(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')s[i] = '0';
    }
}
bool isEnd(int g1, int g2, int left, int turn)
{
    if (g1 == g2)return 0;
    if (g1 < g2)return isEnd(g2, g1, left, !turn);
    if (turn){
        g2++;
        left--;
    }
    g2 += left / 2;
    if (g2 < g1)return 1;
    return 0;
}
int make_match(string &s1, string &s2)
{
    int g1 = 0, g2 = 0;
    int cnt = 0; int tot = 10;
    for (int i = 0; i < s1.size(); i++)
    {
        g1 += s1[i] - '0';
        cnt++;
        if (isEnd(g1, g2, 10 - cnt, 1)) {
            return cnt;
        }
        g2 += s2[i] - '0';
        cnt++;
        if (isEnd(g1, g2, 10 - cnt, 0)) {
            return cnt;
        }
    }
    return cnt;
}
int32_t main()
{
    // aeh();
    W(t)
    {
        // 1 0 1 1 0
        // 0 0 0 0 1
        string s; cin >> s;
        string t1 = "", t2 = "";
        make_teams(s, t1, t2);
        string W1 = t1, F1 = t2;
        win(W1);
        lose(F1);
        // deb(W1)
        // deb(F1)
        int ans = make_match(W1, F1);
        W1 = t1; F1 = t2;
        win(F1);
        lose(W1);
        // deb(W1)
        // deb(F1)
        ans = min(ans, make_match(W1, F1));
        cout << ans << "\n";

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
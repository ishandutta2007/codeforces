// Willpower alone isn't enough in battle 
// You know that, *
// Defeating ** will require far more..
// ~ Armin Arlert, SnK

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'

int main()
{
    fast_io;
    int n;
    cin >> n;
    priority_queue<II> q;
    int mini = 100;
    int maxi = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        int r;
        cin >> r;
        q.push({r,i});
        mini = min(mini, r);
        maxi = max(maxi, r);
        sum += r;
    }
    for(int ans = mini; ans >= 0; ans--) {
       int csum = sum - ans*n;
       //trace(ans,csum,maxi);
       if(maxi-ans <= csum / 2 || ans==0) {
           cout << ans << endl;
           int iter;
           if(csum%2==1 && ans!=0)
           {
               cout << csum/2 << endl;
               iter = (csum/2) - 1;
               II a = q.top();q.pop();
               II b = q.top();q.pop();
               II c = q.top();q.pop();
               a.F--;
               b.F--;
               c.F--;
               q.push(a);
               q.push(b);
               q.push(c);
               for(int i=0;i<n;i++) {
                    int out = 0;
                    if(i==a.S || i==b.S || i==c.S)
                        out = 1;
                    cout << out;
               }
               cout << endl;
           }
           else if(ans!=0)
               cout << (csum+1)/2 << endl, iter = (csum + 1)/2;
           else if(ans==0) {
               iter = 10000;
               cout << iter << endl;
           }
           while(iter--) {
               II a = q.top();q.pop();
               II b = q.top();q.pop();
               a.F--;
               b.F--;
               q.push(a);
               q.push(b);
               for(int i=0;i<n;i++) {
                    int out = 0;
                    if(i==a.S || i==b.S)
                        out = 1;
                    cout << out;
               }
               cout << endl;
           }
           return 0;
       }
    }
    return 0;
}
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define SIZE(x)                     (int)x.size()
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
string base2(ll n){string a = "";while(n >= 2){a += (char)(n % 2 + '0');n /= 2;}a += (char)(n + '0');reverse(all(a));return a;}

const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % MOD, b / 2)) % MOD : pw(a * a % MOD, b / 2))); }

void PRINT(deque<int> dq){
    for(auto x:dq){
        cout << x << " ";
    }
}

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b + 1 && !c && !d){
        cout << "YES";
        cout << endl;
        cout << 0 << " ";
        for(int i = 0; i < b; i++){
            cout << 1 << " " << 0 << " ";
        }
        return 0;
    }
    if(d == c + 1 && !a && !b){
        cout << "YES" << endl;
        cout << 3 << " ";
        for(int i = 0; i < c; i++){
            cout << 2 << " " << 3 << " ";
        }
        return 0;
    }
    bool is_OK = 1;
    if(a > b){
        is_OK = 0;
    }
    if(d > c){
        is_OK = 0;
    }
    if(!is_OK){
        return cout << "NO", 0;
    }
    b -= a;
    c -= d;
    deque<int> ans, ans1;
    for(int i = 0; i < a; i++){
        ans.push_back(0);
        ans.push_back(1);
    }
    for(int i = 0; i < d; i++){
        ans1.push_front(3);
        ans1.push_front(2);
    }
    for(int i = 0; i < min(b, c); i++){
        ans.push_back(2);
        ans.push_back(1);
    }
    int cu = min(b, c);
    b -= cu;
    c -= cu;
    if(b >= 1){
        ans.push_front(1);
        b--;
    }
    if(c >= 1){
        ans1.push_back(2);
        c--;
    }
    if(b > 0 || c > 0){
        return cout << "NO", 0;
    }
    cout << "YES" << endl;
    PRINT(ans);
    PRINT(ans1);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void a(){
    int n;
    cin>>n;
    vi p(n+1);
    F1(i,n) cin>>p[i];
    vi inv(n+1);
    F1(i,n) inv[p[i]]= i;
    vb puse(n+1,false);
    int i = 1;
    while(i <= n){
        puse[inv[i]] = true;
        int j = i;
        while(j < n and inv[j+1] == inv[j]+1) j++;
        if(inv[j] < n and !puse[inv[j]+1]){
            cout<<"No\n";
            return;
        }
        i = j+1;
    }
    cout<<"Yes\n";
}

vector<string> coso = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int decimal(string& s){
    int i = 0;
    int res = 0;
    while(i < s.size()){
        res *= 2;
        if(s[i] == '1') res++;
        i++;
    }
    return res;
}

int trad(int num){
    int i = 0;
    while(i < 10 and decimal(coso[i]) != num) i++;
    if(i == 10) i = -1;
    return i;
}

void b(){
    vvi aux((1<<7),vi(8,-1));
    F0(i,(1<<7)) aux[i][0] = trad(i);
    F1(k,7){
        F0(i,(1<<7)){
            aux[i][k] = -1;
            F0(j,7){
                if((i & (1<<j)) == 0) maxi(aux[i][k],aux[i|(1<<j)][k-1]);
            }
        }
    }
    int n,k;
    cin>>n>>k;
    vi a(n);
    string s;
    F0(i,n){
        cin>>s;
        a[i] = decimal(s);
    }
    vvb puedo(n+1,vb(k+1,false));
    puedo[n][0] = true;
    F0R(i,n){
        F0(j,k+1){
            F0(l,8){
                if(aux[a[i]][l] >= 0 and j-l >= 0) puedo[i][j] = puedo[i][j] or puedo[i+1][j-l];
            }
        }
    }
    if(!puedo[0][k]){
        cout<<"-1\n";
        return;
    }
    F0(i,n){
        int j = 0;
        while(j < 8 and k-j >= 0 and !puedo[i+1][k-j]) j++;
        int uso = j;
        while(j < 8){
            if(k-j >= 0 and puedo[i+1][k-j] and aux[a[i]][j] > aux[a[i]][uso]) uso = j;
            j++;
        }
        a[i] = aux[a[i]][uso];
        k -= uso;
    }
    F0(i,n) cout<<a[i];
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}
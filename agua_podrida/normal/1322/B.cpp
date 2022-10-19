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
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2 == 1){
        cout<<"-1\n";
        return;
    }
    int abren = 0;
    F0(i,n) if(s[i] == '(') abren++;
    if(abren != n/2){
        cout<<"-1\n";
        return;
    }

    int dif = 0;
    int ult;
    int res = 0;
    F0(i,n){
        if(s[i] == '(') {
            dif++;
            if(dif == 0) res += i-ult+1;
        }
        else{
            dif--;
            if(dif == -1) ult = i;
        }
    }
    cout<<res<<'\n';
}

const int N = 1e7+1;
int d[N];

void b(){
    memset(d,0,sizeof(d));
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    F0(i,n) cin>>a[i];
    F0(i,n) d[a[i]]++;
    F1(i,N-1) d[i] += d[i-1];
    sort(todo(a));
    int j = 29;
    int res = 0;
    while(j >= 0){//INV: todos los a[i] menores a (1<<(j+1))
        //cuento para cada a[i] con cuantos k a[i]+a[k] tiene encendido el j-esimo bit
        int l = 0; int r = n-1;
        int cant = 0;
        while(l != r){
            if(a[l] + a[r] < (1<<j)){
                l++;
            }
            else{
                cant += r-l;
                cant %= 2;
                r--;
            }
        }

        l = 0; r = n-1;
        while(l != r){
            if(a[l] + a[r] < (1<<(j+1))){
                l++;
            }
            else{
                cant -= r-l;
                cant += 2;
                cant %= 2;
                r--;
            }
        }
        l = 0; r = n-1;
        while(l != r){
            if(a[l] + a[r] < (1<<j)+(1<<(j+1))){
                l++;
            }
            else{
                cant -= r-l;
                cant %= 2;
                r--;
            }
        }
        if(cant) res += (1<<j);
        F0(i,n) a[i] %= (1<<j);
        int p = 1;
        while(p < n and a[p] >= a[p-1]) p++;
        int i1 = 0;
        int i2 = p;
        while(i1 < p and i2 < n){
            if(a[i1] < a[i2]) {
                b[i1+i2-p] = a[i1];
                i1++;
            }
            else{
                b[i1+i2-p] = a[i2];
                i2++;
            }
        }
        while(i1 < p){
            b[i1+i2-p] = a[i1];
            i1++;
        }
        while(i2 < n){
            b[i1+i2-p] = a[i2];
            i2++;
        }
        a = b;
        j--;
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    b();
    return 0;
}
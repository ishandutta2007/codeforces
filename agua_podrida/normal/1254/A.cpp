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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

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
    int r,c,k;
    cin>>r>>c>>k;
    vector<string> farm(r);
    F0(i,r) cin>>farm[i];
    int arroz = 0;
    F0(i,r) F0(j,c) if(farm[i][j] == 'R') arroz++;

    int paracu = arroz / k;
    int masun = arroz % k;

    vector<string> res = farm;
    char pollo = 'a';
    int i = 0;
    int j = 0;
    F0(p,k){
        if(p == 26) pollo = 'A';
        if(p == 52) pollo = '0';

        int faltan = paracu;
        if(p < masun) faltan++;
        while(faltan > 0) {
            res[i][j] = pollo;
            if (farm[i][j] == 'R') faltan--;

            if (i % 2 == 0) j++;
            else j--;
            if (j == c) {
                j--;
                i++;
            }
            else if (j == -1) {
                j++;
                i++;
            }
        }
        pollo++;
    }

    pollo--;
    while(i < r){
        res[i][j] = pollo;
        if(i%2 == 0) j++;
        else j--;
        if(j == c) {j--; i++;}
        else if(j == -1) {j++; i++;}
    }

    F0(i,r) cout<<res[i]<<'\n';
}
int main() {
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}
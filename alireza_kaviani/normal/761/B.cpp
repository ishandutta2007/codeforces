#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main(){
    fast_io;

    int n, l;
    cin >> n >> l;

    int a[n + 1] , b[n + 1];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < n ; i++)    cin >> b[i];
    a[n] = a[0] + l , b[n] = b[0] + l;

    vector<int> vec(n) , sec(n);
    for(int i = 0 ; i < n ; i++){
        vec[i] = abs(a[i] -a[(i + 1)]);
        sec[i] = abs(b[i] - b[(i + 1)]);
    }

    for(int i = 0 ; i < n ; i++){
        rotate(vec.begin() , vec.begin() + 1 , vec.end());
        int ok = 1;
        for(int j = 0 ; j < n - 1 ; j++){
            if(vec[j] != sec[j]){
                ok = 0;
                break;
            }
        }
        if(ok)  return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;
    return 0;
}
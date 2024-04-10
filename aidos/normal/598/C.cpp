#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

struct pnt{
    long double ang;
    long double x, y;
    int id;
    void read(int _id){
        double a, b;
        cin >> a >> b;
        x = a;
        y = b;
        ang = atan2l(-y,x);
        if(ang < 0.5e-18) ang += 2 * acosl(-1.0);
        id = _id;
    }
    bool operator < (const pnt o) const {
        return ang < o.ang;
    }
};


pnt c[100100];
int n;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0 ; i < n; i++){
        c[i].read(i+1);
    }

    
    sort(c, c + n);
    
    long double mini = 1e12;
    
    for(int i = 1; i < n; i++){
        mini = min(c[i].ang - c[i-1].ang, mini);
    }
    mini = min(2 * acosl(-1.0) - c[n-1].ang + c[0].ang, mini);
    for(int i = 1; i < n; i++){
        if(fabs(mini -c[i].ang + c[i-1].ang) < 0.5e-18L){
            cout << c[i].id << " " << c[i-1].id << endl;
            return 0;
        }
    }
    cout << c[0].id << " "<< c[n-1].id << endl;

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
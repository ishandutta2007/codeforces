#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
ll inverseC(ll x){
    double a = sqrt(1+8*x);
    if(a == ((int) a)){
        return (1+a)/2;
    }
    return -1;
}
static vector<pair<ll, ll>> times;
int main(){
    fast_io();
    ll a, b, c, d;
    cin >> a>>b>>c>>d;
    if(a==0 && b == 0 && c == 0 && d ==0 ){
        cout << 0;
        return 0;
    }
    ll x = inverseC(a);
    ll y = inverseC(d);
    if(a ==0 && b == 0 && c == 0&& y!= -1 ){
        f0r(i, y){
            cout << "1";
        }
        return 0;
    }
    if(d ==0 && b == 0 && c == 0 && x!= -1 ){
        f0r(i, x){
            cout << "0";
        }
        return 0;
    }
    if(a== 0 && d ==0 && c == 0 &&b == 1){
        cout << "01";
        return 0;
    }
    if(a== 0 && d ==0 && b == 0 &&c == 1){
        cout << "10";
        return 0;
    }
    if(x == -1 || y == -1){
        cout << "Impossible";
        return 0;
    }
    if(a+b+c+d != (x+y)*(x+y-1)/2){
        cout << "Impossible";
        return 0;
    }
    if(c> x*y || b> x*y){
        cout << "Impossible";
        return 0;
    }
    if(c == x*y && b == 0){
        f0r(i, y){
            cout << "1";
        }
        f0r(i, x){
            cout << "0";
        }
        return 0;
    }
    if(b == x*y && c == 0){
        f0r(i, x){
            cout << "0";
        }
        f0r(i, y){
            cout << "1";
        }
        return 0;
    }
    ll cur = x;
    ll y1 = y;
    //cout << x << " " << y << endl;
    ll sz2 = 0;
    while(b>0 && y> 0){
        if(b<=cur){
            times.eb(mp(b, 1));
            //cout << "asdf" << endl;
            sz2 += 1;
            y--;
            b = 0;
        }
        else{
            y-= (b/cur);
            //cout <<  b/cur << " asdf " << endl;
            times.eb(mp(cur, b/cur));
            sz2 += (b/cur);
            b = b% cur;

        }
        cur--;
    }
    string s = "";
    //cout << times.size() << endl;
   //cout << x <<  " " << y1 << endl;
    //cout << y1 << " " << sz2 << endl;
    f0r(i, y1 - sz2){
        s += "1";
    }
    sort(all(times));
    f0r(i, times[0].f){
        s+= "0";
    }
    f0r(i, times[0].s){
        s+= "1";
    }
    ll prev = times[0].f;
    f1r(i, 1, sz(times)){
        ll more = times[i].f - prev;
        if(more == 0){
            f0r(j, times[i].s){
                s += "1";
            }
            continue;
        }
        f0r(j, more){
            s += "0";
        }
        f0r(j, times[i].s){
                s += "1";
        }
    }
    ll sz1 = s.size();
    f0r(i, x+y1 -sz1){
        s += "0";
    }
    cout << s << endl;
    return 0;
}
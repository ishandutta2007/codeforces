#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct tank{
    int hp, dt, l, r;
    double p;
    tank(){}
    read(){
        cin >>hp>>dt>>l>>r>>p;
        p /= 100;
    }
};

tank t[2];
int const N = 4000;
double dp1[N][202];
double dp2[N][202];

double pref[100100];

inline double get(const int &l, const int &r){
    if(r <= 0) return (r - l + 1.0)* pref[0];
    if( l <= 0) return pref[r] - pref[0] * l;
    return pref[r] - pref[l-1];
}

inline double get(const int &x){
    return get(x - t[0].r, x - t[0].l);
}


inline double get2(const int &x){
    return get(x - t[1].r, x - t[1].l);
}


int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    t[0].read();
    t[1].read();

    if (t[0].p == 1.0){
        cout <<0<<endl;
        return 0;
    }
    if (t[1].p == 1.0){
        cout <<1<<endl;
        return 0;
    }

    int timer1 = 0, timer2 = 0;
    int t1 = 0, t2 = 0;

    double ans = 0.0;

    dp1[0][0] = 1.0;

    for (int i=1;i<N;i++){
        pref[0] = dp1[i-1][0];
        for(int j = 1; j < 202; j++)
            pref[j] = pref[j - 1] + dp1[i-1][j];
        int len = t[0].r - t[0].l + 1;
        for (int j=1;j<202;j++){
            dp1[i][j] = dp1[i-1][j] * t[0].p + (1.0 - t[0].p) * get(j) / len;       
        }
    }

    for (int i=1;i<202;i++) dp2[0][i] = 1.0;
    if((double)clock() * 1.0 / CLOCKS_PER_SEC > 1.8) assert(false);

    for (int i=1;i<N;i++){
        pref[0] = dp2[i-1][0];
        for(int j = 1; j < 202; j++)
            pref[j] = pref[j - 1] + dp2[i-1][j];
        int len = t[1].r - t[1].l + 1;
        for (int j=1;j<202;j++){
            dp2[i][j] = dp2[i-1][j] * t[1].p + (1.0 - t[1].p) * get2(j)/len;        
        }
    }
    
    

    for (int i=0;i<10000&& t1 < N && t2 < N;i++){
        if ( timer1 <= timer2 ){
            timer1 += t[0].dt;
            t1++;
            ans += dp1[t1][t[1].hp] * dp2[t2][t[0].hp]; //calc1(t[1].hp, t1, 0) * calc2(t[0].hp, t2, 1);
        }
        else {
            timer2 += t[1].dt;
            t2++;
        }
    }

    
    printf("%.10f", ans);



    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}
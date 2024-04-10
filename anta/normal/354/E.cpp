#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

const int luckies[3] = {0,4,7};
char ts[20];
char memo[20][7][10][5];
char keiro[6][20];
char rec(int i, int k, int d, int carry) {
    char &me = memo[i][k][d][carry];
    if(me != -1) return me;
    int r = 0;
    if(i == 19) r = d == 0;
    else if(k == 6) {
        if(d == ts[i]) r |= rec(i+1, 0, carry, 0);
    }else rep(j, 3)
        r |= rec(i, k+1, (d+luckies[j])%10, carry+(d+luckies[j]>=10));
    return me = r;
}
void rec_keiro(int i, int k, int d, int carry) {
    if(i == 19) ;
    else if(k == 6) {
        rec_keiro(i+1, 0, carry, 0);
    }else rep(j, 3) {
        if(rec(i, k+1, (d+luckies[j])%10, carry+(d+luckies[j]>=10))) {
            keiro[k][i] = luckies[j] + '0';
            rec_keiro(i, k+1, (d+luckies[j])%10, carry+(d+luckies[j]>=10));
            return;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        ll t;
        cin >> t;
        rep(i, 20) ts[i] = t % 10, t /= 10;
        mset(memo, -1);
        if(!rec(0, 0, 0, 0)) cout << "-1" << endl;
        else {
            rec_keiro(0, 0, 0, 0);
            rep(k, 6) {
                int lz = 19;
                while(lz != 1 && keiro[k][lz-1] == '0') lz --;
                reverse(keiro[k], keiro[k]+lz);
                keiro[k][lz] = 0;
                cout << keiro[k];
                if(k != 5) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
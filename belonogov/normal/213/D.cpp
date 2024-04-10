#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const double PI = acos(-1);
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct pt {
    double x, y;
    pt () { }
    pt (double xx, double yy): x(xx), y(yy) { }
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    pt operator * (double k) {
        return pt(x * k, y * k);
    }
    pt operator / (double k) {
        return pt(x / k, y / k);
    }
    pt rotate(double alf) {
        return pt(x * cos(alf) - y * sin(alf), x * sin(alf) + y * cos(alf));
    }
    void print() {
        printf("%.17f %.17f\n", x, y);
    }
};

int n;

void read() {
    scanf("%d", &n); 
    pt O(0, 0);
    double T = 10;
    vector<pt> res;
    res.pb(O);
    for (int i = 0; i < n; i++) {
        double alf = PI * 2 / 5;
        double beta = (PI - alf) / 2;
        double R = (T / 2) / sin(alf / 2);   
        pt v(R, 0);
        double teta = 2 * beta - PI / 2;
        assert(teta > 0);
        v = v.rotate(-teta);
        pt H = O + v;
        v = v * (-1); 
        for (int j = 0; j < 4; j++) {
            v = v.rotate(alf * 2);
            O = H + v;
            res.pb(O);
        }
        //db2(O.x, O.y);
    }
    //pt u = O * (-1);
    //u = u / n;
    //for (int i = 0; i < n; i++) {
        //O = O + u;        
        //res.pb(O);
    //}

    printf("%d\n", (int)res.size());
    for (auto p: res)
        p.print();
    

    for (int i = 0; i < n; i++) {
        printf("%d ", i * 4 + 1 + 0);
        printf("%d ", i * 4 + 1 + 3);
        printf("%d ", i * 4 + 1 + 1);
        printf("%d ", i * 4 + 1 + 4);
        printf("%d ", i * 4 + 1 + 2);
        puts("");
    }


    //db(res.size());
    for (int i = 0; i < (int)res.size(); i++)
        printf("%d ", i + 1);
    
    for (int i = res.size() - 5; i >= 0; i -= 4)
        printf("%d ", i + 1);
    puts("");

}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}
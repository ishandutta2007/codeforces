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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
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
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef double dbl;


vector<int> slow(int x) {
    vector<int> res;
    for (int i = 1; i <= x; i++)
        if (x % i <= x / i)
            res.pb(i);
    return res;
}

vector<int> smart(int x) {
    vector<int> tmp;
    int j = 1; 
    for (; j * j <= x; j++) {
        tmp.pb(j);
    }
    if (j * j > x) j--;
    if (j * j == x) j--;

    //db(tmp.size());
    //db(j);
    for (; j > 0; j--) {
        if (x % j == 0 && tmp.back() < x / j - 1) {
            tmp.pb(x / j - 1);
        }
        if (tmp.back() < x / j)
            tmp.pb(x / j);
    }
    return tmp;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);  
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //smart(8);
    //return 0;
    //for (int i = 0; i < 10000; i++) {
        //int x = rand() % 1000 + 1;
        //auto r1 = slow(x);
        //auto r2 = smart(x);
        //db3(x, r1.size(), r2.size());
        //for (auto y: r2)
            //cerr << y << " ";
        //cerr << endl;
        //assert(r1 == r2);
    //}

    vector<int> answer;
    for (int i = 0; i < n; i++) {
        vector<int> tmp = smart(a[i]);
    

        //cerr << a[i] << ": ";
        //for (auto x: tmp)
            //cerr << x << " ";
        //cerr << endl;
        //exit(0);

        
        if (i == 0) {
            answer = tmp;
        }
        else {
            int cur = 0; 
            int k = 0;
            for (auto x: tmp) {
                for (; k < (int)answer.size() && answer[k] < x; k++);
                if (k < sz(answer) && answer[k] == x) {
                    answer[cur++] = x;
                    k++;
                }
            }
            answer.resize(cur);
        }

    }
    assert(!answer.empty());
    int g = answer.back();
    ll sum = 0;
    for (auto x: a) {
        assert(x % g <= x / g);
        ll cnt = x / (g + 1);
        if (x % (g + 1) != 0)
            cnt++;
        sum += cnt;
    }

    cout << sum << endl;





    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}
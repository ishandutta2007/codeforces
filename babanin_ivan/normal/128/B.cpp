#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

string s;
int n;
int64 k;
vector <int> a[50];
vector <int> newt;
int64 kol[50];
int tekl = 0;
string res;

void printerr() {
    cout << "No such line.\n";
    exit(0);
}
void print() {
    cout << res << endl;
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    getline(cin, s);
    cin >> k;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        a[s[i] - 'a' + 1].pb(i);
        kol[s[i] - 'a' + 1] += n - i;
    }
    //s.pb('a' - 1);
    while (true) {
        bool f = false;
        for (int i = 0; i < 35; ++i) 
            if (k > kol[i]) 
                k -= kol[i];
            else {
                if (i == 0)
                    print();
                res.pb(char(i + 'a' - 1));
                newt = a[i];
                for (int i = 0; i < 40; ++i) {
                    a[i].clear();
                    kol[i] = 0;
                }
                kol[0] = newt.size();
                for (int i = 0; i < newt.size(); ++i) 
                    if (newt[i] != (n - 1)) {
                        a[s[newt[i] + 1] - 'a' + 1].pb(newt[i] + 1);
                        kol[s[newt[i] + 1] - 'a' + 1] += n - (newt[i] + 1);
                    }
                f = true;
                break;
            }
        if (!f)
            printerr();
    }
    return 0;
}
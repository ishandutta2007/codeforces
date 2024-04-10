#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d, e, f;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &d, &e, &f);
    int abc[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, haha = 365;
    int aa = 0;
    fop (i,1900,a) {
        aa += haha;
        if (i % 4 == 0) {
            aa++;
            if (i % 100 == 0 and i != 2000) {
                aa--;
            }
        }
    }
    fop (i,0,b-1) {
        aa += abc[i];
        if (i == 1) {
            if (a % 4 == 0) {
                aa++;
                if (a % 100 == 0 and a != 2000) {
                    aa--;
                }
            }
        }
    }
    aa += c;
    fop (i,1900,d) {
        aa -= haha;
        if (i % 4 == 0) {
            aa--;
            if (i % 100 == 0 and i != 2000) {
                aa++;
            }
        }
    }
    fop (i,0,e-1) {
        aa -= abc[i];
        if (i == 1) {
            if (d % 4 == 0) {
                aa--;
                if (d % 100 == 0 and d != 2000) {
                    aa++;
                }
            }
        }
    }
    aa -= f;
    cout << abs(aa) << endl;
}
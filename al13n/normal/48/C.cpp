#include <iostream>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define fill asdfill // fill -      STL;     ,      
#define eps 1e-8

bool fill[1100000];

int main() {

    int n;
    cin >> n;
    int last_known;
    forn(i,n) {
        int a;
        cin >> a;
        fill[a] = true;
        last_known = a;
    }
    double min_alpha = 10;
    double max_alpha = 1e200;
    int fills_done = 1;
    for(int p = 1;; ++p) {
        double alpha = (p * 10 + 10.0) / fills_done;
        if (p <= last_known) {
            if (fill[p]) {
                max_alpha = min(max_alpha, alpha);
                ++fills_done;
            } else {
                min_alpha = max(min_alpha, alpha);
            }
        } else {
            if (max_alpha <= alpha + eps) {
                cout << "unique\n" << p;
                exit(0);
            } else if (min_alpha <= alpha - eps) {
                cout << "not unique";
                exit(0);
            }
        }
    }
    
    return 0;
}
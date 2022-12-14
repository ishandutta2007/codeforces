#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77 , SQ = sqrt(1e9 + 77) + 2;
int w , l;
vector < int > r;
bool check(int x) {
    if(x <= 0) return false;
    if((l % x == 0 && ((w - 2) % x == 0 || ((l - 2) % x == 0 && (w - 1) % x == 0))))
        return true;
    if((w % x == 0 && ((l - 2) % x == 0 || ((w - 2) % x == 0 && (l - 1) % x == 0))))
        return true;
    if(((l - 1) % x == 0 && (((w % x == 0) && (w - 2) % x == 0) || (w - 1) % x == 0)))
        return true;
    if(((w - 1) % x == 0 && (((l % x == 0) && (l - 2) % x == 0) || (l - 1) % x == 0)))
        return true;
    return false;
}
void f(int x) {
    if(check(x)) r.push_back(x);
}
void test() {
    r.clear();
    scanf("%d %d" , & w , & l);
    for(int i = 1;i * i <= max(l , w);++ i) {
        if(l % i == 0) {
            f(i);
            f(l / i);
        }
        if((l - 1) % i == 0) {
            f(i);
            f((l - 1) / i);
        }
        if(w % i == 0) {
            f(i);
            f(w / i);
        }
        if((w - 1) % i == 0) {
            f(i);
            f((w - 1) / i);
        }
    }
    sort(r.begin() , r.end());
    r.resize(unique(r.begin() , r.end()) - r.begin());
    printf("%d " , (int) r.size());
    for(int x : r) printf("%d " , x);
    printf("\n");
}
int main() {

    int tst;
    scanf("%d" , & tst);
    while(tst --)
        test();
    return 0;
}
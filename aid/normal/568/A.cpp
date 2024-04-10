#include <iostream>
#include <vector>

using namespace std;

const int N = 2000 * 1000 + 5;
int lDiv[N];
vector<int> pr;

bool pal(int x) {
    if(!(x % 10))
        return false;
    int y = 0, xx = x;
    while(xx) {
        y = y * 10 + (xx % 10);
        xx /= 10;
    }
    return y == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < N; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            int p = pr[j] * i;
            if(p >= N)
                break;
            lDiv[p] = pr[j];
        }
    }
    int p, q;
    cin >> p >> q;
    int pi = 0, rub = 0, ans = -1;
    for(int i = 1; i < N; i++) {
        if(i > 1 && lDiv[i] == i)
            pi++;
        if(pal(i))
            rub++;
        if((long long)q * pi <= (long long)p * rub)
            ans = i;
    }
    cout << ans << '\n';
    return 0;
}
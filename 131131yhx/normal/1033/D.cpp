#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <vector>

#define int long long
#define P 998244353

using namespace std;

typedef long long ll;

map <int, int> hsh;

int n, A[555];

int get2(int x) {
    int tmp = sqrt(x);
    while(tmp * tmp < x) tmp++;
    while(tmp * tmp > x) tmp--;
    if(tmp * tmp == x) return tmp;
    return -1;
}

int get3(int x) {
    int tmp = exp(log(x) / 3);
    while(tmp * tmp * tmp < x) tmp++;
    while(tmp * tmp * tmp > x) tmp--;
    if(tmp * tmp * tmp == x) return tmp;
    return -1;
}

int get4(int x) {
    int tmp = exp(log(x) / 4);
    while(tmp * tmp * tmp * tmp < x) tmp++;
    while(tmp * tmp * tmp * tmp  > x) tmp--;
    if(tmp * tmp * tmp * tmp == x) return tmp;
    return -1;
}

vector <int> V;

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++) if(A[i] != 1) {
        int tmp;
        if((tmp = get4(A[i])) != -1) hsh[tmp] += 4, A[i] = 1, V.push_back(tmp);
        else if((tmp = get3(A[i])) != -1) hsh[tmp] += 3, A[i] = 1, V.push_back(tmp);
        else if((tmp = get2(A[i])) != -1) hsh[tmp] += 2, A[i] = 1, V.push_back(tmp);
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) if(A[i] != A[j]) {
            int g = gcd(A[i], A[j]);
            if(g != 1) V.push_back(g);
        }
    int ans = 1;
    for(int i = 0; i < V.size(); i++) {
        for(int j = 1; j <= n; j++) {
            int flag = 0;
            while(A[j] % V[i] == 0) {
                flag = 1;
                A[j] /= V[i];
                hsh[V[i]]++;
            }
            if(flag && A[j] != 1) {
                hsh[A[j]]++;
                A[j] = 1;
            }
        }
    }
    for(int i = 1, lst = i; i <= n; i = ++lst) if(A[i] != 1) {
        while(A[lst + 1] == A[i]) lst++;
        ans = ans * (lst - i + 2) % P * (lst - i + 2) % P;
    }
    for(map <int, int>::iterator it = hsh.begin(); it != hsh.end(); it++)
        if(it -> first != 1) ans = ans * (it->second + 1) % P;
    printf("%lld\n", (ans % P + P) % P);
    fflush(stdout);
    return 0;
}
#include <cstdio>
#include <string>
#define ac(a, c) (a == 0 && c == 2)
using namespace std;

typedef long long llint;

int k, x, n, m;
llint f[55];
llint cnt[55][3][3];

string get(string arg, int num) {
    string ret = "";
    while (num--) ret += arg;
    return ret;
}

string gen(int len, int first, int last, int occ) {
    string tmp = get("AC", occ);
    if (2 * occ <= len - 2) 
        return (char)('A' + first) + tmp + get("B", len - 2 * occ - 2) + (char)('A' + last);
    if (2 * occ == len) {
        if (ac(first, last)) return tmp;
        return "";
    }
    if (!first) return tmp + (char)('A' + last);
    if (last == 2) return (char)('A' + first) + tmp;
    return "";
}

int main() {
    
    scanf("%d%d%d%d", &k, &x, &n, &m);
    
    f[1] = f[2] = 1;
    for (int i = 3; i <= k; i++) 
        f[i] = f[i - 1] + f[i - 2];
    
    cnt[3][1][2] = 1;
    for (int i = 4; i <= k; i++) {
        for (int p = 0; p < 3; p++)
            for (int q = 0; q < 3; q++) 
                cnt[i][p][q] = cnt[i - 1][p][q] + cnt[i - 2][p][q];
        cnt[i][2][1 + i % 2]++;
    }
    
    for (llint p = 0; p < 3; p++) 
        for (llint q = 0; q < 3; q++) 
            for (llint r = 0; r < 3; r++) 
                for (llint s = 0; s < 3; s++) {
                    
                    llint occ = (llint)x - ac(q, r) * cnt[k][1][2] - ac(s, p) * cnt[k][2][1] - ac(s, r) * cnt[k][2][2];
                    
                    for (int i = 0; i <= n / 2; i++) 
                        for (int j = 0; j <= m / 2; j++) 
                            if ((llint)i * f[k - 2] + (llint)j * f[k - 1] == occ) {
                                string a = gen(n, p, q, i), b = gen(m, r, s, j);
                                if (!a.empty() && !b.empty()) {
                                    printf("%s\n%s\n", a.c_str(), b.c_str()); 
                                    return 0;
                                }
                            }
                            
            }
    
    puts("Happy new year!");
    
    return 0;
}
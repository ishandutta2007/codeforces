#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define P 1000000007
#define M 5000010

using namespace std;

int Pr[M], A[M], lw[M], S[M], O[M], SS[M], t = 0;

bool npr[M];

signed main() {
    for(int i = 2; i <= 5000000; i++) {
        if(!npr[i]) Pr[++t] = i, lw[i] = i;
        for(int j = 1; Pr[j] * i <= 5000000; j++) {
            npr[Pr[j] * i] = 1;
            lw[Pr[j] * i] = Pr[j];
            if(i % Pr[j] == 0) {
                break;
            }
        }
    }
    int n;
    scanf("%lld", &n);
    //vector <int> V;
    //V.clear();
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%lld", &a);
        O[a]++;
    }
    /*sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for(int i = 0; i < V.size(); i++) {
        int tmp = V[i] - 1;
        while(tmp != 1) {
            int w = lw[tmp];
            int cnt = 0;
            while(tmp % w == 0) tmp /= w, cnt++;
            S[w] = max(S[w], cnt);
        }
    }*/
    for(int i = 5000000; i >= 1; i--) {
        if(O[i] && !S[i]) S[i] = 1, SS[i] = 1, O[i]--;
        if(O[i]) {
            int tmp = i - 1;
            while(tmp != 1) {
                int w = lw[tmp];
                int cnt = 0;
                while(tmp % w == 0) tmp /= w, cnt++;
                if(S[w] == cnt) SS[w]++; else if(cnt > S[w]) SS[w] = 1;
                S[w] = max(S[w], cnt);
            }
        }
    }
    int ans = 1;
    for(int i = 1; i <= 5000000; i++)
        for(int j = 1; j <= S[i]; j++) ans = ans * i % P;
    int s = 0;
    for(int i = 5000000; i >= 1; i--) {
        int flag = 1;
        if(O[i] > 1) flag = 0; else
        if(O[i]) {
            flag = 0;
            int tmp = i - 1;
            while(tmp != 1) {
                int w = lw[tmp];
                int cnt = 0;
                while(tmp % w == 0) tmp /= w, cnt++;
                if(S[w] == cnt && SS[w] == 1) flag = 1;
            }
        }
        s |= !flag;
    }
    printf("%lld\n", ((ans + s) % P + P) % P);
    return 0;
}
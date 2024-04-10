#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[15];
        scanf("%s", s);
        vector <int> sol;
        for (int i = 12; i; i--) {
            if (12 % i) continue;
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int k = j; k < 12; k += i) 
                    ok &= s[k] == 'X';
                if (ok) {
                    sol.push_back(i);
                    break;
                }
            }
        }
        printf("%d ", sol.size());
        for (int i = 0; i < sol.size(); i++)
            printf("%dx%d ", 12 / sol[i], sol[i]);
        puts("");
    }
    return 0;
}
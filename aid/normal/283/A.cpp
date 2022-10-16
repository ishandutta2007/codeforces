#include <cstdio>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int ar[MAXN], add[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    int len = 1;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int a, x;
            scanf("%d %d", &a, &x);
            add[a - 1] += x;
            sum += x * a;
        }
        else if(t == 2) {
            scanf("%d", &ar[len]);
            sum += ar[len];
            len++;
        }
        else if(len >= 2) {
            len--;
            sum -= ar[len] + add[len];
            add[len - 1] += add[len];
            add[len] = 0;
        }
        printf("%.08f\n", (double)sum / len);
    }
    return 0;
}
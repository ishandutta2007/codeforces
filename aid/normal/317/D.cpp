#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int SQRTN = 100 * 1000 + 5, LOGN = 30;
int a[LOGN], gr[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7,
                     4, 2, 1, 10, 9, 3, 6, 11, 12};
char used[SQRTN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int k = 0;
    for(int i = 2; (long long)i * i <= n; i++)
        if(!used[i]) {
            used[i] = true;
            long long p = i * i;
            int q = 1;
            while(p <= n) {
                q++;
                if(p * p <= n)
                    used[p] = true;
                p *= i;
            }
            a[q]++;
            k += q;
        }
    a[1] = n - k;
    int ans = 0;
    for(int i = 1; i < LOGN; i++)
        if(a[i] & 1)
            ans ^= gr[i];
    cout << (ans? "Vasya\n" : "Petya\n");
    return 0;
}
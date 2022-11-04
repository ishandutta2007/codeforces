#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int n, k;

int A[100010];

void check(int x) {
    int nw = 0;
    
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int sm = 0;
    for(int i = 1; i <= n; i++) sm += A[i];
    if(sm % k) {
        puts("No");
        return 0;
    }
    vector <int> V;
    V.clear();
    int nw = 0;
    for(int i = 1; i <= n; i++)
        if((nw += A[i]) > sm / k) {
            puts("No");
            return 0;
        } else if(nw == sm / k) {
            nw = 0;
            V.push_back(i);
        }
    puts("Yes");
    for(int i = 0; i < V.size(); i++) {
        printf("%d ", V[i] - (!i ? 0 : V[i - 1]));
    }
    return 0;
}
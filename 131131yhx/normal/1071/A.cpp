#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a, b;

vector <int> V1, V2;

int main() {
    scanf("%d%d", &a, &b);
    int t = 0, nw = 0;
    while(t + 1 + nw <= a + b) t++, nw += t;
    for(int i = t; i >= 1; i--)
        if(i < a) a -= i, V1.push_back(i);
        else {
            for(int j = 1; j <= i; j++)
                if(j != a) V2.push_back(j);
            if(a) V1.push_back(a);
            break;
        }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    printf("%d\n", V1.size());
    for(int i = 0; i < V1.size(); i++) printf("%d ", V1[i]);
    putchar('\n');
    printf("%d\n", V2.size());
    for(int i = 0; i < V2.size(); i++) printf("%d ", V2[i]);
    putchar('\n');
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

typedef pair <int, string> pii;

const int MAXM = 10005;

int N, M;
vector <pii> V[MAXM];
 
int main() {
    scanf("%d%d", &N, &M);
    while (N--) {
        char name[15];
        int region, points;
        scanf("%s%d%d", name, &region, &points);
        V[region].push_back(pii(points, name));
    }
    
    for (int i = 1; i <= M; i++) {
        sort(V[i].begin(), V[i].end(), greater <pii> ());
        if (V[i].size() > 2 && V[i][1].first == V[i][2].first) {
            puts("?");
            continue;
        }
        printf("%s %s\n", V[i][0].second.c_str(), V[i][1].second.c_str());      
    }
    
    return 0;
}
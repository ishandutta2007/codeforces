#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int d, s, Pr[5010][555][2];

struct node {
    int a, b;
    node() {}
    node(int _1, int _2) {
        a = _1;
        b = _2;
    }
};

int main() {
    scanf("%d%d", &d, &s);
    vector <node> V;
    V.clear();
    V.push_back(node(0, 0));
    memset(Pr, -1, sizeof Pr);
    Pr[0][0][0] = 0;
    for(int i = 0; Pr[s][0][0] == -1 && i < V.size(); i++) {
        int a = V[i].a, b = V[i].b;
        if(a > s) continue;
        for(int j = 0; j < 10; j++)
            if(Pr[a + j][(b * 10 + j) % d][0] == -1) {
                Pr[a + j][(b * 10 + j) % d][0] = j;
                Pr[a + j][(b * 10 + j) % d][1] = b;
                V.push_back(node(a + j, (b * 10 + j) % d));
            }
    }
    if(Pr[s][0][0] == -1) puts("-1"); else {
        vector <int> V;
        int a = s, b = 0;
        while(a != 0) {
            int tmpb = Pr[a][b][1];
            V.push_back(Pr[a][b][0]);
            a -= Pr[a][b][0];
            b = tmpb;
        }
        for(int i = (int) V.size() - 1; i >= 0; i--) printf("%d", V[i]);
    }
    return 0;
}
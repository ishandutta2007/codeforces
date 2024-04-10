#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int a, v;
    node() {}
    node(int x, int y) {
        a = x;
        v = y;
    }
};

vector <node> V[2];

vector <char> Ans;

int n, k;

char ch[2222][2222];

int Mx[2222][2222];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%s", ch[i]);
    for(int i = 0; i <= n; i++) ch[n][i] = (ch[i][n] = 'z' + 1);
    int a = 0, b = 1;
    if(ch[0][0] != 'a') {
        if(!k) Ans.push_back(ch[0][0]);
        else k--, Ans.push_back('a');
    } else Ans.push_back('a');
    V[a].push_back(node(0, k));
    memset(Mx, -1, sizeof Mx);
    Mx[0][0] = k;
    for(int i = 0; i < 2 * n - 2; i++, swap(a, b)) {
        V[b].clear();
        int flag = 0;
        for(int k = 'a'; k <= 'z'; k++) {
            for(int j = 0; j < V[a].size(); j++) {
                int nwA = V[a][j].a, nwB = i - nwA, nwV = V[a][j].v;
                if(Mx[nwA][nwB] != nwV) continue;
                if(nwA != n) {
                    if(ch[nwA + 1][nwB] == k) {
                        flag = 1;
                        if(Mx[nwA + 1][nwB] < nwV) {
                            Mx[nwA + 1][nwB] = nwV;
                            V[b].push_back(node(nwA + 1, nwV));
                        }
                    } else if(nwV) {
                        flag = 1;
                        if(Mx[nwA + 1][nwB] < nwV - 1) {
                            Mx[nwA + 1][nwB] = nwV - 1;
                            V[b].push_back(node(nwA + 1, nwV - 1));
                        }
                    }
                }
                if(nwB != n) {
                    if(ch[nwA][nwB + 1] == k) {
                        flag = 1;
                        if(Mx[nwA][nwB + 1] < nwV) {
                            Mx[nwA][nwB + 1] = nwV;
                            V[b].push_back(node(nwA, nwV));
                        }
                    } else if(nwV) {
                        flag = 1;
                        if(Mx[nwA][nwB + 1] < nwV - 1) {
                            Mx[nwA][nwB + 1] = nwV - 1;
                            V[b].push_back(node(nwA, nwV - 1));
                        }
                    }
                }
            }
            if(flag) {
                Ans.push_back(k);
                break;
            }
        }
    }
    for(int i = 0; i < Ans.size(); i++) putchar(Ans[i]);
    return 0;
}
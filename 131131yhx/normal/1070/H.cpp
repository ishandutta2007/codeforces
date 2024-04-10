#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

struct node {
    int a, c;
    string b;
    node () {a = 0, c = 0, b = "";}
    node(int _1, string _2) {
        a = _1;
        b = _2;
    }
};

map <string, node> hsh;

int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < S.size(); j++)
            for(int o = j; o < S.size(); o++) {
                string V;
                V = "";
                for(int k = j; k <= o; k++) V += S[k];
                if(hsh[V].c == i) continue;
                hsh[V].a++;
                if(hsh[V].a == 1) hsh[V].b = S;
                hsh[V].c = i;
            }
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        string S;
        cin >> S;
        cout << hsh[S].a << " " << (!hsh[S].a ? "-" : hsh[S].b) << endl;
    }
    return 0;
}
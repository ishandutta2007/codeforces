#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 100005;
const int MAXB = 30;

int Q;
int trie[MAXN * MAXB][2];
int dad[MAXN * MAXB], cnt[MAXN * MAXB];
map <int, int> node;
int sz = 1;

void insert(int curr, int bit, int val) {
    cnt[curr]++;
    if (bit == -1) {
        node[val] = curr;
        return;
    }
    int tmp = val >> bit & 1;
    if (trie[curr][tmp] == -1) {
        trie[curr][tmp] = sz++;
        dad[trie[curr][tmp]] = curr;
    }
    insert(trie[curr][tmp], bit - 1, val);
}

void erase(int curr, int val) {
    cnt[curr]--;
    if (!curr) return;
    if (!cnt[curr]) trie[dad[curr]][val % 2] = -1;
    erase(dad[curr], val / 2);
}

int query(int curr, int bit, int val) {
    if (bit == -1) return 0;
    int tmp = val >> bit & 1;
    if (trie[curr][tmp ^ 1] == -1) 
        return query(trie[curr][tmp], bit - 1, val);
    return (query(trie[curr][tmp ^ 1], bit - 1, val) | (1 << bit));
}

int main() {
    scanf("%d", &Q);
    memset(trie, -1, sizeof trie);
    insert(0, MAXB, 0);
    while (Q--) {
        char cmd;
        int x;
        scanf(" %c%d", &cmd, &x);
        if (cmd == '+') insert(0, MAXB, x);
        else if (cmd == '-') erase(node[x], x);
        else printf("%d\n", query(0, MAXB, x));
    }
    return 0;
}
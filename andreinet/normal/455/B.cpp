#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Lenmax = 100005;

struct Node {
    int dp1, dp2;
    Node *links[26];

    Node() {
        memset(links, 0, sizeof(links));
    }
};

Node *Root = new Node();
char word[Lenmax];

void Insert(Node* node, char *s) {
    if (*s == '\n')
        return;

    if (node->links[*s - 'a'] == NULL) node->links[*s - 'a'] = new Node();
    Insert(node->links[*s - 'a'], s + 1);
}

void Dp(Node *node) {
    bool ok = 0;

    for (int i = 0; i < 26; i++)
        if (node->links[i] != NULL)
            ok = 1;

    if (!ok) {
        node->dp1 = 0;
        node->dp2 = 1;
        return;
    }

    node->dp1 = node->dp2 = 0;
    for (int i = 0; i < 26; i++) {
        if (node->links[i] != NULL) {
            Dp(node->links[i]);

            if (!node->links[i]->dp1)
                node->dp1 = 1;

            if (!node->links[i]->dp2)
                node->dp2 = 1;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    while (N--) {
        fgets(word, Lenmax, stdin);
        Insert(Root, word);
    }
    Dp(Root);

    int dp1 = Root->dp1, dp2 = Root->dp2;

    //printf("%d %d\n", dp1, dp2);

    if (dp1 && dp2)
        printf("First\n");
    else if (dp1 && !dp2) {
        if (M & 1)
            printf("First\n");
        else
            printf("Second\n");
    } else if (!dp1)
        printf("Second\n");
}
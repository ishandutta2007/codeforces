#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 2111

struct Node{
    Node *son[26];
    int bg, en;

    Node() {
        for (int i = 0; i < 26; i++)
            son[i] = NULL;
        bg = en = 0;
    }
};

int n, m, i, j;
char pattern[maxN];
char s[maxN];

Node *Head;
int dp[maxN];
pair<int, int> ans[maxN];

vector< pair<int, int> > sol;

void preproc() {
    int i, j;

    for (i = 1; i <= n; i++) {
        Node *act = Head;

        for (j = i; j <= n; j++) {
            int go = pattern[j] - 'a';
            if (act->son[go] == NULL) {
                act->son[go] = new Node;
                act->son[go]->bg = i;
                act->son[go]->en = j;
            }

            act = act->son[go];
        }
    }

    for (i = 1; i <= n; i++) {
        Node *act = Head;

        for (j = i; j >= 1; j--) {
            int go = pattern[j] - 'a';
            if (act->son[go] == NULL) {
                act->son[go] = new Node;
                act->son[go]->bg = i;
                act->son[go]->en = j;
            }

            act = act->son[go];
        }
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n%s\n", pattern + 1, s + 1);
    n = strlen(pattern + 1);
    m = strlen(s + 1);

    Head = new Node();
    preproc();

    dp[0] = 1;

    for (i = 0; i <= m; i++) {
        if (dp[i] == 0) {
            printf("-1");
            return 0;
        }

        Node *act = Head;
        for (j = i + 1; j <= m; j++) {
            int go = s[j] - 'a';
            if (act->son[go] == NULL)
                break;
            act = act->son[go];

            if (dp[j] == 0 || dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                ans[j] = mp(act->bg, act->en);
            }
        }
    }

    dp[m]--;
    printf("%d\n", dp[m]);

    int pos = m;
    for (i = 1; i <= dp[m]; i++) {
        sol.pb(ans[pos]);
        int aux = ans[pos].first - ans[pos].second;
        if (aux < 0) aux *= -1;
        aux++;
        pos -= aux;
    }

    for (i = sol.size() - 1; i >= 0; i--)
        printf("%d %d\n", sol[i].first, sol[i].second);


    return 0;
}
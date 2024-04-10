#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 100005;

struct State {
    int links[26];
    int endPos = -1;
    int len;
    int suffLink;
    vector<int> invLinks;
    State() {
        memset(links, 0xFF, sizeof links);
    }
};

State states[2 * NMAX];
int lastState, cntStates;

void saExtend(char c) {
    int x = c - 'a';
    int curr = cntStates++;
    states[curr].len = states[lastState].len + 1;
    states[curr].endPos = states[lastState].endPos + 1;
    int p;
    for (p = lastState; p != -1 && states[p].links[x] == -1; p = states[p].suffLink) {
        states[p].links[x] = curr;
    }
    if (p == -1) {
        states[curr].suffLink = 0;
    } else {
        int q = states[p].links[x];
        if (states[p].len + 1 == states[q].len + 1) {
            states[curr].suffLink = q;
        } else {
            int clone = cntStates++;
            memcpy(states[clone].links, states[q].links, sizeof states[clone].links);
            states[clone].len = states[p].len + 1;
            states[clone].suffLink = states[q].suffLink;
            for (; p != -1 && states[p].links[x] == q; p = states[p].suffLink) {
                states[p].links[x] = clone;
            }
            states[q].suffLink = clone;
            states[curr].suffLink = clone;
        }
    }
    lastState = curr;
}

int nrPos[2 * NMAX];
bool usedState[2 * NMAX];

int nrSubseq[2 * NMAX];

void dfs(int state) {
    for (int to: states[state].invLinks) {
        dfs(to);
        nrPos[state] += nrPos[to];
    }
    if (states[state].endPos != -1) {
        nrPos[state]++;
    }
}

void dfs1(int state) {
    if (usedState[state]) {
        return;
    }
    usedState[state] = true;
    nrSubseq[state] = nrPos[state];
    for (int i = 0; i < 26; ++i) {
        int to = states[state].links[i];
        if (to != -1) {
            dfs1(to);
            nrSubseq[state] += nrSubseq[to];
            nrSubseq[state] = min(nrSubseq[state], NMAX);
        }
    }
}

bool gotAnswer = false;

void getAnswer(int state, int k, string& ans) {
    int x = state == 0 ? 0: nrPos[state];
    if (state != 0 && k < x) {
        gotAnswer = true;
        return;
    }
    k -= x;
    for (int i = 0; i < 26; ++i) {
        int to = states[state].links[i];
        if (to != -1) {
            if (k < nrSubseq[to]) {
                ans += (char) ('a' + i);
                getAnswer(to, k, ans);
                return;
            } else {
                k -= nrSubseq[to];
            }
        }
    }
}

void buildSuffixAutomaton(const string& S) {
    lastState = 0;
    states[0].len = 0;
    states[0].suffLink = -1;
    cntStates = 1;
    for (char c: S) {
        saExtend(c);
    }
    for (int i = 1; i < cntStates; ++i) {
        states[states[i].suffLink].invLinks.push_back(i);
    }
    dfs(0);
    dfs1(0);
}

int main()
{
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // LOCAL_RUN
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    buildSuffixAutomaton(S);

    int k;
    cin >> k;

    --k;

    string ans;
    getAnswer(0, k, ans);

    if (gotAnswer) {
        cout << ans << '\n';
    } else {
        cout << "No such line.\n";
    }
}
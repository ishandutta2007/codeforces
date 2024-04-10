#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 1000005;

int N;
char buff[MAXN];
bool eq[MAXN], diff[MAXN];
bool taut[MAXN], cont[MAXN];
vector <int> ch[MAXN];
char w[MAXN];

void load() {
    scanf("%d%s", &N, buff);
}

void calc(int x) {
    if (ch[x].size() == 1) {
        int c = ch[x][0];
        eq[x] = eq[c];
        diff[x] = diff[c];     
        taut[x] = taut[c];
        cont[x] = cont[c];   
        return;
    }
    int a = ch[x][0], b = ch[x][1];
    if (w[x] == '&') {
        eq[x] = (eq[a] && eq[b]) || cont[a] || cont[b];
        diff[x] = (taut[a] && diff[b]) || (diff[a] && taut[b]);
        taut[x] = taut[a] && taut[b];
        cont[x] = cont[a] || cont[b];
    }
    if (w[x] == '|') {
        eq[x] = (eq[a] && eq[b]) || taut[a] || taut[b];
        diff[x] = (cont[a] && diff[b]) || (diff[a] && cont[b]);
        taut[x] = taut[a] || taut[b];
        cont[x] = cont[a] && cont[b];
    }
    if (w[x] == '^') {
        eq[x] = (eq[a] && eq[b]) || (diff[a] && diff[b]);
        diff[x] = (eq[a] && diff[b]) || (diff[a] && eq[b]);
        taut[x] = (taut[a] && cont[b]) || (cont[a] && taut[b]);
        cont[x] = (taut[a] && taut[b]) || (cont[a] && cont[b]);
    }
}

bool solve() {
    stack <int> S;
    string s = buff;
    s = '(' + s + ')';
    for (int i = 0; i < s.size(); i++) 
        if (s[i] == '(')
            S.push(i);
        else if (s[i] == ')') {
            int curr = S.top();
            calc(curr);
            S.pop();
            if (!S.empty())
                ch[S.top()].push_back(curr);
        }
        else if (isdigit(s[i])) {
            ch[S.top()].push_back(i);
            eq[i] = true;
            diff[i] = false;
            taut[i] = s[i] == '1';
            cont[i] = s[i] == '0';
        }
        else if (s[i] == '?') {
            ch[S.top()].push_back(i);
            eq[i] = false;
            diff[i] = true;
            taut[i] = false;
            cont[i] = false;
        }
        else w[S.top()] = s[i];
        
    return !eq[0];
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}
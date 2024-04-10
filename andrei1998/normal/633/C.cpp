#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct trie {
    int word;
    trie *alf[26];

    trie() {
        word = 0;
        memset(alf, 0, sizeof alf);
    }
} *root;

string words[100005];
string word;

void add_word(int index) {
    trie *current = root;

    for (auto it: word) {
        if (!current -> alf[it - 'a'])
            current -> alf[it - 'a'] = new trie;
        current = current -> alf[it - 'a'];
    }

    current -> word = index;
}

int father[100005];

char big_string[100005];

int main()
{
    root = new trie;

    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    cin.get();
    cin.get(big_string + 1, 100005);

    int m = 0;
    cin >> m;
    for (int i = 1; i <= m; ++ i) {
        cin >> words[i];
        word = words[i];
        reverse(word.begin(), word.end());
        for (auto &it: word)
            if (isupper(it))
                it = tolower(it);
        add_word(i);
    }

    father[n + 1] = -1;
    for (int i = n; i; -- i) {
        trie *current = root;

        for (int j = i; j <= n; ++ j) {
            if (!current -> alf[big_string[j] - 'a'])
                break;
            else {
                current = current -> alf[big_string[j] - 'a'];
                if (current -> word && father[i + words[current -> word].size()]) {
                    father[i] = current -> word;
                    break;
                }
            }
        }
    }

    vector <string> sol;

    int where = 1;
    while (father[where] != -1) {
        sol.push_back(words[father[where]]);
        where += words[father[where]].size();
    }

    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map <string, int> hsh;

string S[100010], SS[100010];

char ch[100010];

int bel[100010];

int main() {
    int n = 0;
    for(; ;) {
        gets(ch);
        int st = strlen(ch);
        n++;
        for(int i = 0; i < st; i++) S[n] += ch[i];
        if(ch[0] == 92 && ch[1] == 'e') break;
    }
    int cnt = 0, i;
    for(i = 0; i < n; i++)
        for(int j = 0; j < S[i].size(); j++)
            if(S[i][j] == 92 && S[i][j + 1] == 'c') {
                int l = j + 6, r = j + 6;
                while(S[i][r] != '}') r++;
                string s = "";
                for(int k = l; k < r; k++) s += S[i][k];
                hsh[s] = ++cnt;
            } else if(S[i][j] == 92 && S[i][j + 1] == 'b') goto bomb;
bomb:;
    int tmp = i, s = n - 1 - tmp;
    for(i++; i <= n - 1; i++) {
        int l = 9, r = l;
        while(S[i][r] != '}') r++;
        string s = "";
        for(int k = l; k < r; k++) s += S[i][k];
        bel[i] = hsh[s];
    }
    int flag = 0;
    for(int i = 1; i <= s; i++)
        if(bel[tmp + i] != i) flag = 1;
    if(!flag) {
        puts("Correct");
        return 0;
    }
    puts("Incorrect");
    for(int i = 1; i <= s; i++) SS[bel[i + tmp]] = S[i + tmp];
    cout << S[tmp] << endl;
    for(int i = 1; i <= s; i++) cout << SS[i] << endl;
    cout << S[n] << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string word;
    int u = 0;
    int l = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> word;
    int len = word.length();
    for(int i = 0; i < len; i ++) {
        if(word[i] > 95) {
            l ++;
        } else {
            u ++;
        }
    }
    if(l >= u) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    } else {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    }
    cout << word;
    return 0;
}
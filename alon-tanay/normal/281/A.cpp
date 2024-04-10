#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> word;
    cout << char(toupper(word[0]));
    cout << word.erase(0,1);
    return 0;
}
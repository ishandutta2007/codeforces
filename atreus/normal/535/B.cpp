#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main (){
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 1; i < s.size(); i++)
        ans += pow(2, i);
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '7'){
            ans += pow(2, s.size() - i - 1);
        }
    }
    cout << ans + 1 << endl;
}
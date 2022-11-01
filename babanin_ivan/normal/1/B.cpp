#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int t;
string s;

bool is_letter(char c) {
    if ((c >= 'A') && (c <= 'Z'))
        return true;
    return false;
}

//BC23
void solve1() {
    string temp;
    temp.clear();
    int k = 0;
    for (int i = 0; i < s.size(); ++i)
        if (!is_letter(s[i]))
            temp.pb(s[i]);
        else ++k;
    printf("R%sC", temp.c_str());
    int cur = 1;
    int sum = 1;
    for (int i = 0; i < k - 1; ++i) {
        cur *= 26;
        sum += cur;
    }
    int cur2 = 0;
    for (int i = 0; i < k; ++i)
        cur2 = cur2 * 26 + int(s[i]) - int('A');
    printf("%d\n", cur2 + sum);
}

//R23C55
void solve2() {
    string temp, temp2;
    temp.clear();
    temp2.clear();
    int x = 0;
    int j = 1;
    while (s[j] != 'C') {
        temp.pb(s[j]);
        ++j;
    }
    ++j;
    while (j < s.size()) {
        x = x * 10 + int(s[j]) - int('0');
        ++j;
    }
    int cur = 1;
    int k;
    for (k = 1;;++k) {
        x -= cur;
        cur *= 26;
        if (x <= cur)
            break;
    }
    //cur /= 26;
    //x -= cur;
    while (x) {
        temp2.pb(char((x % 26) + int('A')));
        x /= 26;
    }
    while (temp2.size() < k)
        temp2.pb('A');
    reverse(temp2.begin(), temp2.end());
    printf("%s%s\n", temp2.c_str(), temp.c_str());
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  
    scanf("%d ", &t);
    for (int z = 0; z < t; ++z) {
        scanf(" ");
        getline(cin, s);
        int i = 0;
        while (is_letter(s[i]))
            ++i;
        bool f = true;
        for (int j = i; j < s.size(); ++j)
            if (is_letter(s[j]))
                f = false;
        if (f)
            solve1();
        else solve2();
    }
    return 0;
}
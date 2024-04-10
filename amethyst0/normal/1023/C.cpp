#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const int maxn = (int)2e5 + 10;
char s[maxn], t[maxn];

vector <int> pos;

int main() {
    int n, k;
    
    cin >> n >> k;
    
    scanf("%s", s);
    
    vector <int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            pos.push_back(st.back());
            pos.push_back(i);
            st.pop_back();
        }
        
        if ((int)pos.size() == k) {
            break;
        }
    }
    
    sort(pos.begin(), pos.end());
    
    for (int i = 0; i < k; i++) {
        printf("%c", s[pos[i]]);
    }
    
    return 0;
}
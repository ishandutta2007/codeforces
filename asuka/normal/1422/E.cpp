#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 7;

char s[maxn];

struct Node {
    int len;
    int flag; //
    string pre,suf;
    char fir;
    void push(char ch) {
        if(ch != fir)
            flag = (ch < fir);
        len++;
        fir = ch;
        pre = ch + pre;
        if(pre.size() > 10) {
            if(suf.size() < 2) {
                suf = pre.back() + suf;
                pre.pop_back();
                suf = pre.back() + suf;
            }
            pre.pop_back();
        }
    }
}ans[maxn];

int main() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = n;i >= 1;i--) {
        if(i + 1 <= n && s[i] == s[i + 1]) {
            ans[i] = ans[i + 2];
            if(ans[i].fir > s[i] || (ans[i].fir == s[i] && ans[i].flag)) {
                ans[i].push(s[i]);
                ans[i].push(s[i]);
            }
        } else {
            ans[i] = ans[i + 1];
            ans[i].push(s[i]);
        }
    }
    for(int i = 1;i <= n;i++) {
        printf("%d ",ans[i].len);
        if(ans[i].len > 10) {
            cout << ans[i].pre.substr(0,5);
            cout << "...";
            cout << ans[i].suf << endl;
        } else {
            cout << ans[i].pre << endl;
        }
    }
    return 0;
}
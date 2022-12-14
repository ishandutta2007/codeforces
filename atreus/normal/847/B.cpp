#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
int a[maxn + 100];
stack <int> s[maxn + 100];

void check(int n){
    int l = 0, r = maxn;
    while (r - l > 1){
        int x = (r + l) / 2;
        if (s[x].empty() || s[x].top() < n){
            r = x;
        }
        else
            l = x;
    }
    s[r].push(n);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        check(a[i]);
    }
    for (int i =
          1; i <= n; i++){
        int b[maxn];
        int p = 1;
        while (!s[i].empty() && s[i].size() > 0){
            b[p] = s[i].top();
            s[i].pop();
            p ++;
        }
        for (int j = p - 1; j >= 1; j--)
            cout << b[j] << " ";
        cout << endl;
    }
}
#include<bits/stdc++.h>

using namespace std;

const int maxn = 111111;
int a[maxn], b[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack <int> s;
    for (int i = n - 1; i >= 0; i--){
        if (s.size() == 0){
            s.push(a[i]);
            b[i] = 0;
            continue;
        }
        if (a[i] > s.top()){
            s.push(a[i]);
            b[i] = 0;
            continue;
        }
        else {
            b[i] = s.top() - a[i] + 1;
            continue;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
}
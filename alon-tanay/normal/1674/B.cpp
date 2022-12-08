#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        char c;
        cin >> c;
        int a = c - 'a';
        cin >> c;
        int b= c - 'a';
        if(a < b) {
            b --;
        }
        cout << a * 25 + b + 1 << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;
string s;
queue<int> Z, P;

int dist(int x, int y, int z) {
    return abs(x - y) + abs(y - z);
}

bool can(int d) {
    queue<int> z = Z, p = P;
    while(!p.empty() && !z.empty()) {
        int d0 = abs(z.front() - p.front());
        if(d0 <= d) { //     
            int x0 = p.front(), x1 = z.front();
            while(!z.empty() && min(dist(x0, x1, z.front()), dist(x0, z.front(), x1)) <= d)
                z.pop();
        }
        p.pop();
    }
    return z.empty();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        if(s[i] == '*') Z.push(i);
        else if(s[i] == 'P') P.push(i);
    int bl = 1, br = 2 * n;
    while(bl < br) {
        int bm = (bl + br) / 2;
        if(can(bm)) br = bm;
        else bl = bm + 1;
    }
    cout << bl;
}
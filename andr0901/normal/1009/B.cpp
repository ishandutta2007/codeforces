#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    char c;
    int t = 0, one = 0;
    queue <int> q;
    while (cin >> c) {
        if (c == '1') one++;
        else if (c == '0') t++;
        else if (c == '2') {
            q.push(t);
            t = 0;
        }
    }
    q.push(t);
    for (int j = 0; j < q.front(); j++) cout << 0;
    q.pop();
    for (int j = 0; j < one; j++) cout << 1;
    while(!q.empty()) {
        cout << 2;
        for (int j = 0; j < q.front(); j++) cout << 0;
        q.pop();
    }
    return 0;
}
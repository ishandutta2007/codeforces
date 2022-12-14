#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 4e5;
pair <int, string> p[maxn + 200];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p[2 * i].first = a;
        p[2 * i].second = "1st";
        p[2 * i + 1].first = b;
        p[2 * i + 1].second = "fi";
    }
    sort (p, p + 2 * n);
    int k = 0;
    for (int i = 0; i < 2 * n; i++){
        if (p[i].second == "1st")
            k ++;
        if (p[i].second == "fi")
            k --;
        if (k > 2)
            return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
}
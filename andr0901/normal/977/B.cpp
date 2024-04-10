#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int findd(vector < pair <string, int> > a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first == b) return i;
    }
    return -1;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector < pair <string, int> > a;
    for (int i = 0; i < n - 1; i++) {
        string b = "";
        b += s[i];
        b += s[i + 1];
        if (findd(a, b) == -1) a.push_back({b, 0});
        else a[findd(a, b)].second++;
    }
    int m = a[0].second;
    int l = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].second > m) {
            m = a[i].second;
            l = i;
        }
    }
    cout << a[l].first;
    return 0;
}
#include <iostream>


using namespace std;

pair <int, int> p[400];
int a, b;

bool check (int o, int e){
    if (a < b)
        swap (a, b);
    int fr = p[o].first + p[e].first;
    int sr = p[o].second + p[e].second;
    if (fr <= a && p[o].second <= b && p[e].second <= b)
        return true;
    if (fr <= b && p[o].second <= a && p[e].second <= a)
        return true;
    if (sr <= a && p[o].first <= b && p[e].first <= b)
        return true;
    if (sr <= b && p[o].first <= a && p[e].first <= a)
        return true;
    fr = p[o].first + p[e].second;
    sr = p[o].second + p[e].first;
    if (fr <= a && p[o].second <= b && p[e].first <= b)
        return true;
    if (fr <= b && p[o].second <= a && p[e].first <= a)
        return true;
    if (sr <= a && p[o].first <= b && p[e].second <= b)
        return true;
    if (sr <= b && p[o].first <= a && p[e].second <= a)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (check(i, j)){
                int k = (p[i].first * p[i].second) + (p[j].first * p[j].second);
                ans = max(ans, k);
            }
        }
    }
    cout << ans << endl;
}
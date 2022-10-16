#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > b(n);
    vector<char> v(n);
    for(int i = 0; i < n; i++)
        cin >> b[i].first >> b[i].second;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && b[i].second == b[j].first)
                v[j] = true;
    int k = 0;
    for(int i = 0; i < n; i++)
        if(!v[i])
            k++;
    cout << k << '\n';
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> V(N); for(int&x: V) cin >> x;
        cout << (min_element(V.begin(), V.end()) - V.begin() + 1) << " " << \
        (max_element(V.begin(), V.end()) - V.begin() + 1) << endl;
    }
}
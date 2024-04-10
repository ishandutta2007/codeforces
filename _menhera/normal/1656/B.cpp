#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N, k; cin >> N >> k;
        vector<int> V(N); for(int&x: V) cin >> x;
        sort(V.begin(), V.end());
        bool ans = 0;
        for(int x: V) if(binary_search(V.begin(), V.end(), x+k)) ans = 1;
        cout << (ans ? "YES":"NO") << endl;
    }
}
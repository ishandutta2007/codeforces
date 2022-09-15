#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> V(N); for(int&x: V) cin >> x;
        sort(V.begin(), V.end());
        bool e1 = binary_search(V.begin(), V.end(), 1);
        bool ed = 0;
        for(int i=0; i<N-1; ++i) if(V[i]+1 == V[i+1]) ed = 1;
        if(e1 && ed) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        int s = 0;
        for(int i=0; i<N; ++i)
        {
            int t; cin >> t; s += t;
        }
        if(s%N == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
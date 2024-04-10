#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    int M; cin >> M;
    while(M--)
    {
        int L, R, K; cin >> L >> R >> K;
        L--; K = K % (R-L);
        s = s.substr(0, L) + s.substr(R-K, K) + s.substr(L, (R-K)-L) + s.substr(R);
    }
    cout << s << endl;
}
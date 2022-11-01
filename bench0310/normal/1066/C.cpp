#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    const int N=200005;
    vector<int> pos(N,0);
    int l=0;
    int r=1;
    while(q--)
    {
        char t;
        int id;
        cin >> t >> id;
        if(t=='L') pos[id]=l--;
        else if(t=='R') pos[id]=r++;
        else cout << min(pos[id]-l,r-pos[id])-1 << "\n";
    }
    return 0;
}
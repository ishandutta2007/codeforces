#include<bits/stdc++.h>
using namespace std;
bool is_pal(string s)
{
    string e(s.rbegin(), s.rend());
    return s == e;
}
int main()
{
    string s; cin >> s;
    int ans = 0;
    for(int i=0; i<s.size(); ++i)
        for(int j=i+1; j<=s.size(); ++j)
        {
            string x(s.begin()+i, s.begin()+j);
            if(!is_pal(x)) ans = max(ans, j-i);
            
        }
        
    cout << ans << endl;
    return 0;
}